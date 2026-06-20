# Competitive Programming

Personal repo for solving competitive programming contests in C++.

## Goal

Practice consistently and push rating up toward 2300+, as a stepping stone toward HFT-style quant/dev roles.

## Structure

```
cf/
├── template.cpp     # base template with fast IO
├── new.sh            # create a new problem (folder + .cpp + .in + .out)
├── run.sh            # compile, run, and diff against expected output
└── <contest_id>/
    └── <letter>/
        ├── <letter>.cpp
        ├── <letter>.in
        └── <letter>.out
```

One folder per contest, one subfolder per problem.

## Usage

Create a new problem:

```bash
./new.sh 2237 a
```

This creates `2237/a/a.cpp`, `2237/a/a.in`, `2237/a/a.out`.

Run and check:

```bash
./run.sh 2237/a
```

This compiles `a.cpp` into a temporary binary, runs it against `a.in`, diffs the result against `a.out`, and removes the binary afterward.
`OK` means the output matches. `WRONG ANSWER` prints a diff between expected and actual output.