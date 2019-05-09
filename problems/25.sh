a=0
b=1
i=0
while [ $i -lt $1 ];
do
  a=$(( $a + $b ))
  echo -n "$a, "
  b=$(( $a - $b ))
  i=$(( $i + 1 ))
done