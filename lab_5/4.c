#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    typedef enum { true, false } bool;
    int fd;
    size_t size, size2;
    char string[1000];
    char old[] = "qwerty";
    char new[] = "hello";
    fd = open("file4.txt", O_RDONLY, 0666);
    if(fd < 0){
        fd = open("file4.txt", O_RDONLY|O_CREAT, 0666);
        if(fd < 0) printf("Can\'t open file");
    }
    size = read(fd, string, 1000);
    close(fd);
    fd = open("file4.txt", O_TRUNC, 0666);
    close(fd);
    fd = open("file4.txt", O_WRONLY, 0666);
    int length = strlen(string);
    bool flag;
    for(int i = 0; i < length; i++){
        if(string[i] == old[0]){
            flag = true;
            for(int j = 0; j < strlen(old); j++){
                if(string[i + j] != old[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true){
                for(int j = i + strlen(old); j < length; j++){
                    string[j - strlen(old)] = string[j];
                }
                length -= strlen(old);
                for(int j = length - 1; j >= i; j--){
                    string[j + strlen(new)] = string[j];
                }
                length += strlen(new);
                for(int j = 0; j < strlen(new); j++){
                    string[i + j] = new[j];
                }
            }
        }
    }
    size2 = write(fd, string, length);
    if(close(fd) < 0){
        printf("Can\'t close file");
    }
    return 0;
}

