#! /bin/bash

max=0
moyenne=0
test_nb=100
value_nb=500
min_val=1
max_val=5000
for i in `seq 1 $test_nb`
do
    arg=`shuf -i $min_val-$max_val -n $value_nb`
    arg=`echo $arg | sed 's/\n/ /g'`
    current=`./push_swap $arg | wc -l`
    error=`./push_swap $arg | ./checker $arg`
    if [ $error != "OK" ]
    then
        echo "$arg\n$error\n" >> error
    fi
    moyenne=`expr $moyenne + $current`
done
moyenne=`expr $moyenne / $test_nb`
echo -e "
For $test_nb different tests with $value_nb 
\n average : $moyenne 
\n checker : $error\n"
