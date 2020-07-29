#include<stdio.h>
#include<unistd.h>

//int checksum(int *data);
void test_void_func(void);

int main(void)
{
#if 0
	int i,j,k=0;
	int rows;

	printf("Enter number of rows: ");
	scanf("%d", &rows);

	printf("\n");
#endif

#if 0
	for(i=1;i<=rows;i++) {
		for(j=1;j<=i;j++) {
			printf("%d ", j);
		}
		printf("\n");
	}
#endif
#if 0
	for(i=1;i<=rows;i++,k=0) {
		for(j=1;j<=(rows - i);j++) {
			printf("  ");
		}
		while(k != 2*i-1) {
			printf("* ");
			++k;
		}
		printf("\n");
	}
	for(i=rows;i>0;i--,k=0) {
		for(j=1;j<=(rows - i);j++) {
			printf("  ");
		}
		while(k != 2*i-1) {
			printf("* ");
			++k;
		}
		printf("\n");
	}
#endif
#if 0
	int i;
	int sum = 0;
	int data[64] = {0x11};

	sum = checksum(data);
#endif
		test_void_func();
}
#if 0
int checksum(int *data)
{
	int i;
	int sum = 0;
	
	for(i=64;i>0;i--) {
		sum += *(data++);
	}

	return sum;
}
#endif
void test_void_func(void)
{

}

