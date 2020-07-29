#include<stdio.h>
#include<stdlib.h>

#define ROW 	3
#define COLUMN 	4

int main(void)
{
	int *ptr;
	int **dptr;


	ptr = (int*)malloc(ROW * sizeof(int));
	printf("size of ptr %ld %ld\n", sizeof(*ptr), sizeof(ptr));
	for(int i=0; i<ROW; i++) {
		printf("%p ", ptr+i);
	}

	dptr = (int **)malloc(ROW * sizeof(int *));
	for(int i=0; i<ROW; i++) {
		printf("%p ", dptr+i);
	}

	free(ptr);

	free(dptr);
}
