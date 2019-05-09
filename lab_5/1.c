#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int fd;
    size_t size;
    char my_string[] = "Hello, world!";
    (void)unmask(0);
    if((fd=open("myfile",O_WRONLY | O_CREAT, 0666)) < 0) {
        printf("Can\'t open file\n");
        exit(-1);
    }
    size = write(fd, my_string, 14);
    if(size!=14){
        printf("Can\'t write all string\n");
        exit(-1);
    }
    if(close(fd) < 0) {
        printf("Can\'t close file\n");
    }
    return 0;
}