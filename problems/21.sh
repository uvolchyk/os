n=0
sum=0
while [ $n -le $1 ]
	do
	sum=$(( $sum + $n ))
	n=$(( $n + 1 ))
	done
echo "Среднее значение:"
echo "scale=5; $sum / $1" | bc
