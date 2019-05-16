if [ $1 = 1 ] || [ $1 = 2 ]; then echo Это простое число && exit 1; fi
c=$(echo "scale=0; sqrt($1)" | bc -l)
i=2;
while [ $i -le $c ]
do
	if [ $(( $1 % $i )) = 0 ]; then
		echo "Это составное число"
		exit 1;
	fi
	i=$(( $i + 1 ));
done
echo "Это простое число"
