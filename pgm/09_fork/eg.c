#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>


void main(void)
{
	fork();
	fork();
	fork();
	printf("Hello world\n");
}


