checkLeap()
{
  input=$1
  if ((input % 400 == 0)); then
    return 0
  elif ((input % 100 != 0 && input % 4 == 0)); then
    return 0
  else
    return 1
  fi
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
    nl_i=$end
    while ((i < nl_i)) ; do
        if ((arr[i] <= mid)) ; then
            ((i += 1))
        elif ((arr[nl_i] > mid)) ; then
            ((nl_i -= 1))
        elif ((i < nl_i)) ; then
            teml=${arr[i]}
            arr[i]=${arr[nl_i]}
            arr[nl_i]=$teml
        fi
    done
    quickSort $start $((i - 1))
    quickSort $i $end
}

echo "Enter the size of array."
read n

echo "Enter an array of years."

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
nl_i=0
l_i=0
while ((i <= n))
do
	checkLeap ${arr[i]}
	result=$?
	if ((result == 1)); then
		nl[nl_i]=${arr[i]}
		nl_i=$((nl_i + 1))
	else
		l[l_i]=${arr[i]}
		l_i=$((l_i + 1))
	fi
	i=$((i + 1))
done

echo "Leap Years: "${l[*]}
echo "Non-Leap Years: "${nl[*]}