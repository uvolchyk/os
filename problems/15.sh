if [ $1 -ge $(( $2 + $3 )) ] || [ $2 -ge $(( $1 + $3 )) ] || [ $3 -ge $(( $2 + $1 )) ]; then
	echo "Это не треугольник"
elif [ $(( $1 * $1 )) = $(( $(( $2 * $2 )) + $(( $3 * $3 )) )) ] || [ $(( $2 * $2 )) = $(( $(( $1 * $1 )) + $(( $3 * $3 )) )) ] || [ $(( $3 * $3 )) = $(( $(( $2 * $2 )) + $(( $1 * $1 )) )) ]; then
	echo "Это прямоугольный треугольник";
elif [ $(( $1 * $1 )) > $(( $(( $2 * $2 )) + $(( $3 * $3 )) )) ] || [ $(( $2 * $2 )) > $(( $(( $1 * $1 )) + $(( $3 * $3 )) )) ] || [ $(( $3 * $3 )) > $(( $(( $2 * $2 )) + $(( $1 * $1 )) )) ]; then
	echo "Это тупоугольный треугольник";
else 
	echo "Это остроугольный треугольник";
fi
