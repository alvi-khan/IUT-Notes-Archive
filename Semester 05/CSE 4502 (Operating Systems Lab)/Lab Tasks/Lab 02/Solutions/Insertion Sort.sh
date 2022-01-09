echo "Enter the size of array."
read n

echo "Enter an array of numbers."

flag=0
while [ $flag -eq 0 ]
do
    flag=1

    for((i=0;i<n;i++))
    do
        read arr[$i]
        input=${arr[$i]}

        if [[ -n ${input//[0-9]/} ]]; then
            echo "You can only enter numbers! Please enter a new array."
            flag=0
            break
        elif [ -z "$input" ]
        then
            echo "Empty value! Enter a new array."
            flag=0
            break
        fi
    done
done

for((i=1;i<n;i++))
do
    key=${arr[$i]}
    j=`expr $i - 1`

    while [ $j -ge 0 -a ${arr[$j]} -gt $key ]
    do
        arr[`expr $j + 1`]=${arr[$j]}
        j=`expr $j - 1`
    done

    arr[`expr $j + 1`]=$key
done

echo ${arr[*]}