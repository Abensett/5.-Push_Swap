#! /bin/bash

max=0
nombredetest=100
nombredarg=100
min_val=1
max_val=1000
for i in `seq 1 $nombredetest`
do
    arg=`shuf -i $min_val-$max_val -n $nombredarg`
    arg=`echo $arg | sed 's/\n/ /g'`
    current=`./push_swap $arg | wc -l`
    isok=`./push_swap $arg | ./checker_linux $arg`
    
    if [ $current -gt $max ]
    then
        max="$current"
        worst="$arg"
    fi
done
echo "for $nombredetest tests with $nombredarg different values from $min_val to $max_val:max instructions case is $max and test $isok"
echo "for $nombredetest tests with $nombredarg different values from $min_val to $max_val:max instructions case is $max and test $isok" >> result.txt
