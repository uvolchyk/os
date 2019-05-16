i=0;
sum=0;
while [ $i -le $1 ]
do
echo $(echo "$2^$i" | bc -l);

i=$(( $i + 1 ))
done
echo $sum
