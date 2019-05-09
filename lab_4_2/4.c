#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int spawn (char* program, char** arg_list){
    pid_t child_pid;
    child_pid = fork();
    if(child_pid) 
        return child_pid;
    else{
        execvp(program, arg_list);
        fprintf(stderr, "an error in execvp\n");
        abort();
    }
}
int main(){
    int child_status;
    char* arg_list[] = {"ls", "-l", "/", NULL};
    spawn("ls", arg_list);
    wait(&child_status);
    printf("done\n");
    return 0;
}