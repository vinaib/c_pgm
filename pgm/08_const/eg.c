#include<stdio.h>

void main(void)
{
	/* pic is pointer to constant integer */
	int const *pic;

	/* pci is pointer to constant integer */
	const int *pci;

	int a = 5;

	pic = &a;

	pci = pic;

	/* cpi is pointer constant/constant pointer to integer.
	 * Which means, we can change value to which this this pointer
	 * points, but we cannot change the pointer variable to point to
	 * another address
	 */
	int b = 10, c = 20;
	int * const cpi = &b;

	++b;
	
	/* compiler error, chaging vvalue of pointer constant 
	 * cpi = &c;
	 */

	/* compiler error, even a is not constant. Why error?
	 * Because *p declared as pointer to constant int.
	 * Even pic points to non constant integer, if we try to change value
	 * of "a" through pointer then compiler will throw error, but we can 
	 * change value "a" directly.
	 *
	 * printf("%d\n", ++(*pic));
	 * *pci = 10;	//change value of a indriectly, compiler error
	 */

	printf("%d\n", ++a);
}
