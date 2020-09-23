#include<stdio.h>

struct no_pack {
	char c;
	int i;
	short s1;
};

struct pack {
	char c;
	int i;
	short s1;
}__attribute__((__packed__));


int main(void)
{
	struct no_pack np;
	struct pack p;

	printf("size of np %ld\n", sizeof(np));
	printf("size of p %ld\n", sizeof(p));
}
