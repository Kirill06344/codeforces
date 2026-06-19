# Competitive Programming

Personal repo for solving competitive programming contests in Go.

## Goal

Practice consistently and push rating up toward 2300+, as a stepping stone toward HFT-style quant/dev roles.

## Structure

```
cf/
├── template.go      # base template with fast IO
├── new.sh            # create a new problem (folder + .go + .in + .out)
├── run.sh            # run a solution and diff against expected output
└── <contest_id>/
    └── <letter>/
        ├── <letter>.go
        ├── <letter>.in
        └── <letter>.out
```

One folder per contest, one subfolder per problem.

## Usage

Create a new problem:

```bash
./new.sh 2237 a
```

This creates `2237/a/a.go`, `2237/a/a.in`, `2237/a/a.out`.

Run and check:

```bash
./run.sh 2237/a
```

`OK` means the output matches `a.out`. `WRONG ANSWER` prints a diff between expected and actual output.
