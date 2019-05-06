if [ $# -ne 3 ]; then
	echo "Количество аргументов не равно 3"
	exit 1
fi

sum=0
for n in $@ 
do
	sum=$(( $sum + $n ))
done
echo "Среднее значение суммы аргументов:"
echo "scale=5; $sum / $#" | bc


