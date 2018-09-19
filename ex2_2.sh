#!/usr/bin/bash
if test ! -f numbers
then
    echo 0 > numbers
fi

if ln numbers numbers.lock
then
    for i in `seq 1 10`
    do
        last_num=`tail -1 numbers`
        last_num=$((last_num+1))

        echo $last_num >> numbers
    done

    rm numbers.lock
    fi
