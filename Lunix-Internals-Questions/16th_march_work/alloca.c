#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char *name = (char *) alloca (10);

    strcpy(name, "lunix");

    printf("The copied string data is = %s\n", name);
    
    return 0;

}