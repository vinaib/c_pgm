#include<stdio.h>

int test(unsigned int a)
{
	switch(a)
	{
	case 1: printf("1\n"); break;
	default: printf("default\n");
	case 2: printf("2\n"); break;
	}

	 printf("test func\n");
}
