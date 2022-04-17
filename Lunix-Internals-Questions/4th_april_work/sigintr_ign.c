/* show how to how to ignore */

#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main() {
    signal(SIGINT, SIG_IGN);    // Resgister signal handler 

   // for(int i = 0;;i++) {   //infinite loop
        printf("Inside the function\n");
        sleep(1);   // Delay for 1 sec
    //}
    
    return 0;
}