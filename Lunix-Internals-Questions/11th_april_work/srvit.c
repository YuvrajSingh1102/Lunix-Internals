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

#define PORT 8000
#define MAXSZ 100
int main()
{
    int sockfd;
    int newsockfd;
    
    struct sockaddr_in serverAddress;
    struct sockaddr_in clientAddress;
      //  char buf[200];
    //char *serv_ip = "127.0.0.1";
    int n;
    char msg[MAXSZ];
    int clientAddressLength;

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //initialize the socket addresss
    memset(&serverAddress, 0, sizeof(serverAddress));
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddress.sin_port = htons(8000); // htonl(INADDR_ANY);
    
    bind(sockfd,(struct sockaddr *) &serverAddress, sizeof(serverAddress));

    listen(sockfd, 5);

    while(1) {
        printf("\n********server waiitng for new client connections:*****\n");
        clientAddressLength = sizeof(clientAddress);
        newsockfd = accept(sockfd,(struct sockaddr *) &clientAddress, &clientAddressLength);

        while(1) {
            n = recv(newsockfd, msg, MAXSZ, 0);
            if(n == 0) {
                close(newsockfd);
                break;
            }
            msg[n] = 0;
            send(newsockfd, msg, n, 0);

            printf("Recieve and set: %s\n", msg);
        }
    }
    return 0;
}