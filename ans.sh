#!/usr/bin/env bash

diff="000 001 010 011 100 101 110 111"

outfile=$(mktemp)

for f in $diff; do
    for g in $diff; do
        if g++ -fsanitize=address -fsanitize=undefined -Wall -std=c++17 $f/$g.cpp; then
            if ./a.out > $outfile; then
                echo -n $f-$g: 
                cat $outfile
                echo
            else
                echo $f-$g:RE
            fi
        else
            echo $f-$g:CE
        fi
    done
done