#include <stdio.h>
#include <stdlib.h>

int main(){
    int return_value;
    return_value = system("ls -l/");
    printf("Возвращаемое значение:%d\n", return_value);
    return return_value;
}