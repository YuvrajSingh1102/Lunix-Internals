/*
Explain showing hor to implement tcp/ip server
*/

#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>

/*follwing function will be handling the client in child process */

int main() {
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    
    //int sockfd, n, retval;
    //pid_t childpid;
    //socklen_t clilen;

    //struct sockaddr_in cliaddr, servaddr;
    char buffer[1024] = {0};
    char *hello = "hello from server";

    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit (EXIT_FAILURE);
    }
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_RESUSEPORT, &opt, sizeof(opt))){
        perror("Setsockopt");
        exit (EXIT_FAILURE);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //htonl(INADDR_ANY);
    servaddr.sin_port = htons(8000); //TCP protocol HTTP------port

    retval = bind(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if(retval < 0) {
        perror("blind: ");
        exit(2);
    }
    printf("Socket bound to port 8000\n");
    clilen = sizeof(struct sockaddr_in);

    while(1) {
        printf(" Before recvfrom\n");
        n = recvfrom(sockfd, buf,10000, 0,(struct sockaddr *) &cliaddr, &clilen);
        printf(" rec'd %d bytes\n", n);
        buf[n] = '\0';
        printf("msg from client = %s\n", buf);
    }
}