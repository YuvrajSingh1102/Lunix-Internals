#include <stdio.h>
#include <string.h>

int main() {
    char dest[] = "Oldstring";
    char src[] = "newstring";
    
    printf("Before memmove destination = %s, src = %s\n", dest, src);
    memmove(dest, src, 4);
    printf("After memmove destination = %s, src = %s\n", dest, src);
    return 0;

}