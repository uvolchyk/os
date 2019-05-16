#include <stdio.h>

int main(){
	char c;
	scanf("%c", &c);
	if (c >= '0' && c <= '9'){
		printf("%s\n", "Это цифра");
}
	else if (c >= 'A' && c <= 'z')
{
		printf("%s\n", "Это буква");
}	else
		{printf("%s\n", "Это специальный символ");}
	return 0;
}
