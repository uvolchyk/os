#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t child_pid;
    printf("ID процесса основной программы: %d\n", (int)getpid());
    child_pid = fork();
    if(child_pid){
        printf("Это родительский процесс с ID %d\n", (int)getpid());
        printf("Дочерний процесс с ID %d\n", (int)child_pid);
    }
    else {
        printf("Дочерний процесс с ID %d\n", (int)getpid());
        return 0;
    }
}