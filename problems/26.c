#include <stdio.h>
#include <math.h>
static int
factorial (int n)
{
	return (n < 2) ? 1 : n * factorial(n-1);
}

int main(){

int n;
double x;

printf("%s", "Введите номер суммы ряда: ");
scanf("%d", &n);
printf("%s", "Введите точку, в которой вычисляем сумму: ");
scanf("%lf", &x);

double sum = 0;

for (int i = 0; i <= n; i++){
	double deg;
	double tmp = x;	
	for (int j = 0; j < i; j++){
		tmp = tmp*tmp;
	}
	sum=sum+(tmp / factorial(i));
}

printf("%f\n", sum);

return 0;
}
