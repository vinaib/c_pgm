#include<stdio.h>

struct emp {
	int id;
	char *name;
	char *job;
};

int main(void)
{

	printf("offset of job is %p\n", &((struct emp*)0)->job);

}
