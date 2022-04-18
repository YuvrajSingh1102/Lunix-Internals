/*
To get the details of all the netries available in /etc/sercices (services database).

*/

#include<netdb.h>
#include<stdio.h>
int main() {
    char **names;
    int i;
    struct servent *se = NULL;

    while( (se = getservent())!=NULL) {
        printf("---------------\n");
        printf("Offical Services Name = %s\n", se->s_name);
        printf("Port number = %d\n", ntohs(se->s_port));
        printf("Protocol = %s\n", se->s_proto);

        names = se->s_aliases;

        for(i = 0; names[i]!= NULL; i++)
            printf("--------%s---------", names[i]);

        printf("---------------\n");
    }
}