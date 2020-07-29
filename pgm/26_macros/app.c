#include<stdio.h>

#define stringify(x) #x

#define ABS(x) (((x) < 0) ? -(x) : (x))

int main(void)
{
	int m = ABS(5++);

	printf("m %d\n", m);

	printf("%s\n", stringify(23));

	
}
