#include <stdio.h>

#include <fcntl.h>

int main() {
	int fd1, fd2, fd3, fd4;
	fd2 = open("Q1.txt", O_CREAT | O_RDWR, 777);
	fd3 = open("/home/einfochips/Desktop/lunix internl/Q1.c", O_RDWR, 777);
	
	printf("fd2 return is: %d\n", fd2);
	printf("fd3 return is: %d\n", fd3);
	
	close(fd2);
	close(fd3);

	return 0;
}
