#include <stdio.h>
#include <unistd.h>

int main(){
    printf("Номер процесса: %d\n", (int) getpid());
    printf("Номер родительского процесса: %d\n", (int) getppid());
    return 0;
}