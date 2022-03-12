#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
    int fd;
    int len;
    char write_buf[50] = "heloo how are you";
    char read_buf[50];

    fd = open("lunix.txt", O_CREAT | O_RDWR, 777);

    len  = write(fd, write_buf, 50);

    printf("return value of from write opn =%d\n", len);// 50 return, curr file off mved 50 th location
    lseek(fd,0,SEEK_SET); //rewind current file offset to (0 location) start point int file "linux_kernel.txt"
    read(fd, read_buf,len );

    printf("data from buffer(read optn) =%s\n", read_buf);

    close(fd);
    return 0;
}