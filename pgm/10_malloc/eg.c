#include<stdlib.h>
#include<unistd.h>

void main(void)
{
	int *ptr;

	while(1) {
		ptr = (int *)malloc(1024 *1024);
		usleep(5);
	}
}
