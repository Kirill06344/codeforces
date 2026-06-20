#!/usr/bin/env bash
# usage: ./run.sh 2237/a
DIR="$1"
NAME=$(basename "$DIR")

BIN=$(mktemp)
trap 'rm -f "$BIN"' EXIT

g++ -O2 -std=c++17 -o "$BIN" "$DIR/$NAME.cpp" || exit 1
"$BIN" < "$DIR/$NAME.in" > /tmp/actual.out

if diff -Bbq "$DIR/$NAME.out" /tmp/actual.out > /dev/null; then
  echo "OK"
else
  echo "WRONG ANSWER"
  diff -Bb "$DIR/$NAME.out" /tmp/actual.out
fi