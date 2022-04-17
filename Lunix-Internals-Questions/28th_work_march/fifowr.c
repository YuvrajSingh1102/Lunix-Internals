#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main() {
    int fd1;

    mkfifo("newfifo", 0666);

    char str1[100], str2[100];
    while(1) {
        
        //First open in read only and read
        fd1 = open("Newfifo", O_RDONLY);

        read(fd1, str1, 100);

        //Printf the read string and close
        printf("User1: %s\n", str1);
        close(fd1);

        //Now open in write mode and write
        //string taken from user

        fd1 = open("Newfifo", O_WRONLY);
        fgets(str2, 100, stdin);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
}