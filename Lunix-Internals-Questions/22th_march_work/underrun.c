#include<stdio.h>
#include<stdlib.h>

extern int EF_PROTECT_BELOW;
void buggy()
{
int *intptr;
int i;
intptr=(int *)malloc(sizeof(int)*5);
//printf("MALLOC checking : Addr=%08x and size=%d\n",intptr,sizeof(int )*5);
for(i=0;i<3;i++)
{
*intptr=100;
printf("value at ptr intptr =%d\n",(*intptr));
intptr--;
}
}


int main()
{
buggy();
return 0;
}

