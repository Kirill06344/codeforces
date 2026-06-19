#!/usr/bin/env bash
# usage: ./new.sh 2237 a
mkdir -p "$1/$2"
cp template.go "$1/$2/$2.go"
touch "$1/$2/$2.in"
touch "$1/$2/$2.out"
echo "created $1/$2/$2.go, $2.in, $2.out"