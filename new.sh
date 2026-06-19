#!/usr/bin/env bash
# usage: ./new.sh 2237 a
mkdir -p "$1/$2"
cp template.go "$1/$2/$2.go"
echo "created $1/$2/$2.go"