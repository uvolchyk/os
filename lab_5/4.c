#include <conio.h>
#include <stdio.h>
#include <io.h>
#include <stdlib.h>
int main()
{
 
        FILE *f1,*f2;//2 файла
        char nameIn[20];//имя файла1(длина)
        char nameOut[20];//имя файла2(длина)
        char str[100] ;//строка в файле
        int size;//переменная
        printf("Vvedite imy faila: ");   //спрашиваешь имя
        scanf("%s",nameIn);       //считываешь имя
        f1 = fopen(nameIn,"r");//открываем файл 1
        while (f1 == NULL)//цикл от ошибок,если не сущевствует файла1
        {
              printf("\tError!\n");
              printf("Vvedite imy faila: ");   //спрашиваешь имя
              scanf("%s",nameIn);       //считываешь имя
              f1 = fopen(nameIn,"r");//открытие файла1
        }
        size = filelength(fileno(f1));//получаем размер файла
        int readsize = fread(str,sizeof(char),sizeof(char)*size,f1);//читают строку из файла по символам.в переменную readsize записывается размер
        for(int i=0;i<readsize;i++)//цикл замены букв в строке из файла
        {
                        if( str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 'c')//происходит замена букв
                                 {
                                 str[i] = 'd';
                                 str[i+1] = 'e';
                                 str[i+2] = 'f';
                                 }
        }
        printf("Vvedite imy vihodnogo faila: ");   //спрашиваешь имя
        scanf("%s",nameOut);       //считываешь имя
        f2 = fopen(nameOut,"w");//открытие файла2
        printf("\n");
        printf("\tRezultat izmeneniy: \n");
        for(int i=0;i<readsize;i++)//цикл показа результата на экране монитора
        {
                printf("%c",str[i]);
                fprintf(f2,"%c",str[i]);
        }
        fclose(f2);//закрытие файла2
        fclose(f1);//закрытие файла1
getch() ;
}