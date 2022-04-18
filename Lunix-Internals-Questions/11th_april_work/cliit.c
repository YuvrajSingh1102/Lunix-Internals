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
#define SERVER_IP "127.0.0.1"
#define MAXSZ 100
int main()
{
    int sockfd;
    //int newsockfd;
    
    struct sockaddr_in serverAddress;
    //struct sockaddr_in clientAddress;
      //  char buf[200];
    //char *serv_ip = "127.0.0.1";
    int n;
    char msg1[MAXSZ];
    char msg2[MAXSZ];
    int clientAddressLength;

    //create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    //initialize the socket addresss
    memset(&serverAddress, 0, sizeof(serverAddress));
    
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(SERVER_IP);
    serverAddress.sin_port = htons(PORT); // htonl(INADDR_ANY);
    
    connect(sockfd,(struct sockaddr *) &serverAddress, sizeof(serverAddress));

    //listen(sockfd, 5);

    while(1) {
        printf("\n********Enter message to send to server:*****\n");
        fgets(msg1, MAXSZ, stdin);
        if(msg1[0] == '#')
        break;

        n = strlen(msg1)+1;
        send(sockfd, msg1, n, 0);

        n = recv(sockfd, msg2, MAXSZ, 0);

        printf("Recieve messaqge from server :: %s\n", msg2);
    }
    return 0;
}