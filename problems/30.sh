remainder=1;
t1=$1;
t2=$2;
if [ $1 = 0 ]
then
gcd=$1
exit 0
fi
while [ "$remainder" -ne 0 ]
do
remainder=$(( $t1 % $t2 ));
t1=$t2;
t2=$remainder;
done
gcd=$t1

echo НОК = $(( $(( $1 * $2 )) / $gcd ))
