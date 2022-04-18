/*
Explain showing hor to implement tcp/ip server
*/

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *serv_ip = "127.0.0.1";
    int sockfd, ret_val;
    struct sockaddr_in servaddr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8000); // htonl(INADDR_ANY);
    inet_pton(AF_INET, serv_ip, &servaddr.sin_addr);
    ret_val = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    if (ret_val < 0)
    {
        perror("Connect: ");
        exit(1);
    }

    printf("Client established connection with server\n");

    close(sockfd);
}
