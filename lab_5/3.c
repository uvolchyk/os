#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1, fd2, fd3;
    size_t size1, size2, size3;
    char my_string1[512], my_string2[512], my_string3[1024];
    (void)umask(0);
    if((fd1=open("file1",O_RDONLY)) < 0) {
        printf("Can\'t open file\n");
        exit(-1);
    }
    if((fd2=open("file2",O_RDONLY)) < 0) {
        printf("Can\'t open file\n");
        exit(-1);
    }
    if((fd3=open("myfile",O_WRONLY | O_CREAT, 0666)) < 0) {
        printf("Can\'t open file\n");
        exit(-1);
    }
    size1 = read(fd1, my_string1, 1423);
    size2 = read(fd2, my_string2, 1423);
    strcpy(my_string3, my_string1);
    strcat(my_string3, my_string2);
    size3 = size1 + size2 + 2;
    if(size1 == 15) { write(fd3, "14", 3); }
    write(fd3, my_string3, size3);
    if(close(fd1) < 0) {
        printf("Can\'t close file\n");
    }
    close(fd2);
    close(fd3);
    return 0;
}
