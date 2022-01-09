echo "Array size:"
read n

echo "Array:"

for((i=0;i<n;i++))
do
    read arr[$i]
    input=${arr[$i]}

    if [[ -n ${input//[0-9]/} ]] || [ -z "$input" ]; then
        echo "Please enter integers. Start again."
        i=-1
        continue
    fi
done

echo ${arr[*]}

merge() {
  
  n=`expr $2 - $1 + 1`
  m=`expr $3 - $2`

  for ((i=0; i<n; i++))
  do
    L[$i]=${arr[`expr $1 + $i`]}
  done
  for ((j=0; j<m; j++))
  do
    M[$j]=${arr[`expr $2 + 1 + $j`]}
  done
  
  i=0
  j=0
  k=$1

  while [ $i < $n && $j < $m ]
  do
    if (( L[$i] -le M[$j] )); then
      arr[$k]=${L[$i]}
      i=`expr $i + 1`
    else
      arr[$k]=${M[$j]}
      j=`expr $j + 1`
    fi
    k=`expr $k + 1`
  done

  while [ $i < $n ]
  do
    arr[$k]=${L[$i]}
    i=`expr $i + 1`
    k=`expr $k + 1`
  done

  while [ $j < $m ]
  do
    arr[$k]=${M[$j]}
    j=`expr $j + 1`
    k=`expr $k + 1`
  done
}

mergeSort() {
  if (( $1 < $2 )); then
      m=`expr $2 - $1`
      m=`expr $m / 2`
      m=`expr $m + $1`
      n=`expr $m + 1`
      
      mergeSort $1 $m
      mergeSort $n $2

      merge $1 $m $2
  fi
}

m=`expr $n - 1`
mergeSort 0 $n
echo ${arr[*]}