#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd1, fd2, fd3;
    size_t size;
    char* my_string;
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
    read(fd1, my_string, 512);
    read(fd2, my_string, 512);
    write(fd3, my_string, 512);
    if(close(fd3) < 0) {
        printf("Can\'t close file\n");
    }
    close(fd2);
	close(fd1);
    return 0;
}
