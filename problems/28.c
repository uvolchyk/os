#include <stdio.h>

int Cnk(int N, int K)
{
	return ( (N<K) ? 0 : ((K == 0) ? 1 : ((N-K+1)/K*Cnk(N,K-1))) );
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int j = 0; j <= n; j++){
	for (int i = 0; i <= j; i++){
	printf("%d ", Cnk(j, i));
	
}
printf("%c", '\n');
}
return 0;
}
