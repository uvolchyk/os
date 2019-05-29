#include <stdio.h>

int sumOfDigit(int num)
{
	if (num < 10)
		return num;
	else
		return (num%10)+sumOfDigit(num/10);
}

int main()
{
	int n;
	printf("%s", "Введите число: ");
	scanf("%d", &n);
	printf("%s", "Сумма цифр числа: ");
	printf("%d\n", sumOfDigit(n));
return 0;
}
