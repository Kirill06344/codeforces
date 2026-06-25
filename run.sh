#!/usr/bin/env bash
# usage: ./run.sh 2237/a
DIR="$1"
NAME=$(basename "$DIR")

CPPFILE="$DIR/$NAME.cpp"
if [ ! -f "$CPPFILE" ]; then
  echo "не найден $CPPFILE"
  exit 1
fi

BIN=$(mktemp)
ACTUAL=$(mktemp)
trap 'rm -f "$BIN" "$ACTUAL"' EXIT

echo "Компилирую $CPPFILE..."
g++ -O2 -std=c++17 -o "$BIN" "$CPPFILE" || exit 1

# собираем все тест-кейсы вида <name>.in, <name>1.in, <name>2.in, ...
shopt -s nullglob
TESTS=("$DIR"/*.in)

if [ ${#TESTS[@]} -eq 0 ]; then
  echo "не найдено ни одного .in файла в $DIR"
  exit 1
fi

PASSED=0
FAILED=0

for INFILE in "${TESTS[@]}"; do
  TESTNAME=$(basename "$INFILE" .in)
  OUTFILE="$DIR/$TESTNAME.out"

  if [ ! -f "$OUTFILE" ]; then
    echo "пропускаю $TESTNAME — нет файла $TESTNAME.out"
    continue
  fi

  "$BIN" < "$INFILE" > "$ACTUAL"

  if diff -Bbq "$OUTFILE" "$ACTUAL" > /dev/null; then
    echo "[OK]   $TESTNAME"
    PASSED=$((PASSED+1))
  else
    echo "[FAIL] $TESTNAME"
    echo "  --- input ---"
    sed 's/^/  /' "$INFILE"
    echo "  --- expected ---"
    sed 's/^/  /' "$OUTFILE"
    echo "  --- got ---"
    sed 's/^/  /' "$ACTUAL"
    echo ""
    FAILED=$((FAILED+1))
  fi
done

echo ""
echo "passed: $PASSED, failed: $FAILED"

if [ "$FAILED" -ne 0 ]; then
  exit 1
fi