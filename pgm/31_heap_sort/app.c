#include<stdio.h>
#include<stdint.h>
#include<heap_sort.h>


int32_t main(void)
{
	//int32_t h[] = {0,2,5,8,9,4,10,7};
	int32_t h[] = {0,10,20,30,25,5,40,35};
	
	/* Heap
	 * 40,25,35,10,5,20,30
	 */

	int32_t i;

	for (i=2;i<=7;i++)
		insert_element_into_heap(h, i);

	printf("Elements in Heap: ");
	for(i=1;i<=7;i++) 
		printf("%d ", h[i]);

	printf("\n");

	for(i=7;i>1;i--)
		delete_element_from_heap(h, i);

	printf("Heap Sort: ");
	for(i=1;i<=7;i++) 
		printf("%d ", h[i]);

	printf("\n");

#if 0
	insert_element_into_heap(h, 2);
	insert_element_into_heap(h, 5);
	insert_element_into_heap(h, 8);
	insert_element_into_heap(h, 9);
#endif

	return 0;
}



