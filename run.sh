#!/usr/bin/env bash
# usage: ./run.sh 2237/a
DIR="$1"
NAME=$(basename "$DIR")

GOFILE="$DIR/$NAME.go"
INFILE="$DIR/$NAME.in"
OUTFILE="$DIR/$NAME.out"

go run "$GOFILE" < "$INFILE" > /tmp/actual.out

if diff -Bbq "$OUTFILE" /tmp/actual.out > /dev/null; then
  echo "OK"
else
  echo "WRONG ANSWER"
  echo "--- diff (expected | got) ---"
  diff -Bb "$OUTFILE" /tmp/actual.out
fi