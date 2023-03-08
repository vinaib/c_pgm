#include<stdio.h>
#include<stdlib.h>
#include<string.h>

static void write_overflow_compilemem(void)
{
	int i;
	int arr[5] = {1,2,3,4,5};

	for (i=0;i<=50;i++) {
		arr[i] = 100;		/*arr overflows on i==5 */
	}
}

static void write_overflow_dynmem(void)
{
	char *dest, src[] = "abcd56789123456789";

	dest = malloc(8);
	if(!dest) 
		printf("malloc failed\n");

	strcpy(dest, src); 	/* Bug: write overflow */
	free(dest);
}

static void write_underflow(void)
{
	char *p = malloc(8);

	if(!p) printf("malloc failed\n");

	p--;

	strncpy(p, "abcd5678", 8);	/* Bug write underflow */

	free(++p);
}

void null_access()
{
	int *p = NULL;

	*p = 10;

	printf("p = %d\n", *p);

	return;
}

void segFault()
{
   char *buf;
   
   buf = malloc(1 << 31);
   fgets(buf, 1024, stdin);

   printf("%s\n", buf);

   return;
}

int main()
{
	//write_underflow();
	//write_overflow_compilemem();
	//write_overflow_dynmem();
   segFault();
}
