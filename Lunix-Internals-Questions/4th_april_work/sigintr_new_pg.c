#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

void signal_handler(int signal) {
    if(signal == SIGUSR2){
    printf("Recieved a SIGUSR2 signal\n");
    }
    exit(0);
}

int main(int argc, const char * argv[]) {
    printf("Registring the signal gandler\n");

    signal(SIGUSR2, signal_handler);

    printf("Raising a SIGUSR2 Signal\n");

    // Raise the SIGUSR2 signal
    raise(SIGUSR2);

    // display a meesage indication we are leaving main
    printf("Finished main\n");   
    
    
    
    return 0;
}