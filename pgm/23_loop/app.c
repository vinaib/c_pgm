#include<stdio.h>
void test_void_func();

int main(void)
{
	test_void_func();

   for(unsigned int i = 5; i>=0; i--)
   {
      printf("%d ", i);
   }
   printf("\n");
}

void test_void_func(void)
{
	int a = 0;

	a = a + 1;

	return;
}
