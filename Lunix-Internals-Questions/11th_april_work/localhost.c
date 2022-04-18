/*
To get the details of the hosts
*/

#include<stdio.h>
#include<netdb.h>

int main(int argc, char *argv[]) {
    struct hostent *lh = gethostbyname("127.0.0.1");
    
    if (lh)
        puts(lh->h_name);
    else
        herror("Getgostbyname"); 

    return 0;
}