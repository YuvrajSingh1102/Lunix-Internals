#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

int main() {
    printf("Server - listening");

    //Create fifo
    int code = mkfifo("cli_ser_fifo", 0764);

    if(code == -1) {
        perror("mkfifo returemed an error - file ma already exist");
    }

    //Open read end
    int fd = open("cli_ser_fifo",O_RDONLY);
    if(fd == -1) {
         perror("cannot open FIFI for read");
         return 0;
    }

    printf("FIFO OPEN");

    //Read string (upto 100 charcters)

    char servercv[100];
    memset(servercv, 0, 100);

    int res;
     char Len;

     read(fd, servercv, 100);

     printf("Server recieved: %s\n", servercv);

     printf("EOF Readched");

     close(fd);
     printf("FIFO Closed");
     printf("FIFO Closed");

     return 0;

}