echo "Количество элементов: $#"
sum=0;
for i in $@
	do
		sum=$(( $sum + $i ));
	done
echo "Сумма элементов: $sum"
