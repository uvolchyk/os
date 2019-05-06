if [ $1 -gt 0 ] && [ $2 -gt 0 ]; then
	echo "Первая четверть"
elif [ $1 -lt 0 ] && [ $2 -gt 0 ]; then
	echo "Вторая четверть"
elif [ $1 -lt 0 ] && [ $2 -lt 0 ]; then
	echo "Третья четверть"
elif [ $1 -gt 0 ] && [ $2 -lt 0 ]; then
	echo "Четвёртая четверть"
else
	echo "Точка лежит на координатной прямой"
fi
