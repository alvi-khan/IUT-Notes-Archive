checkPrime()
{
    input=$1
    if ((input <= 1)) ; then
        return 0
    fi

    index=2
    sqrt=$(bc <<< "scale=0; sqrt($input)")
    while ((index <= sqrt))
    do
    	mod=$((input % index))
    	if ((mod == 0)); then
    		return 0
    	fi
    	index=$((index + 1))
    done
    return 1;
}

quickSort()
{
    start=$1
    end=$2
    if ((start >= end)) ; then
        return
    fi
    mid=$(((arr[start]+arr[end])/2))
    i=$start
    np_i=$end
    while ((i < np_i)) ; do
        if ((arr[i] <= mid)) ; then
            ((i += 1))
        elif ((arr[np_i] > mid)) ; then
            ((np_i -= 1))
        elif ((i < np_i)) ; then
            temp=${arr[i]}
            arr[i]=${arr[np_i]}
            arr[np_i]=$temp
        fi
    done
    quickSort $start $((i - 1))
    quickSort $i $end
}

echo "Enter the size of array."
read n

echo "Enter an array of numbers."

for((i=0;i<n;i++))
do
    read arr[i]
    input=${arr[i]}

    if [[ -n ${input//[0-9]/} ]] || [ -z "$input" ]; then
        echo "Please enter integers. Start again."
        i=-1
        continue
    fi
done

quickSort 0 $((n - 1))

i=0
np_i=0
p_i=0
while ((i <= n))
do
	checkPrime ${arr[i]}
	result=$?
	if ((result == 0)); then
		np[np_i]=${arr[i]}
		np_i=$((np_i + 1))
	else
		p[p_i]=${arr[i]}
		p_i=$((p_i + 1))
	fi
	i=$((i + 1))
done

echo "Primes: "${p[*]}
echo "Non-primes: "${np[*]}