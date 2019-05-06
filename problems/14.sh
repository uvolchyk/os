if [ $(( $1 % 4 )) != 0 ]; then
	echo "Обычный год"
elif [ $(( $1 % 100 )) == 0 ]; then
	if [ $(( $1 % 400 )) == 0 ]; then
		echo "Високосный год"
	else
		echo "Обычный год"
	fi
else
	echo "Високосный год"
fi
