#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
    int fd1, fd2, fd3, fd4, x;
    char write_buff[50] = "Course started Lunix";
    char read_buff[50];

    fd1 = open("Q1.txt", O_CREAT | O_RDWR, 777);
    printf("The value of fd2 is: %d\n", fd1);

    if(fd1<0) {
        printf("File not created\n");
    }
    x = write(fd1, write_buff, 50);
    
    lseek(fd1, 0, SEEK_SET);
    read(fd1, read_buff, x);
    

    printf("The value in the read buff is: %s\n", read_buff);

    close(fd1);

    return 0;
}