#!/usr/bin/bash
if test ! -f numbers
then
    echo 0 > numbers
fi

for i in `seq 1 10`;
do
	last_num=`tail -1 numbers`
	last_num=$((last_num+1))

	echo $last_num >> numbers
done
