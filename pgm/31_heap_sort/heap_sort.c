#include<heap_sort.h>

void create_heap(int32_t h[], int32_t n)
{

}

int32_t delete_element_from_heap(int32_t h[], int32_t n)
{
	int32_t i,j,x, temp, val;

	/* take last element to temp */
	x = h[n];

	/* val contains deleted element */
	val = h[1];

	/* copy last element to root node, as we have to delete root */
	h[1] = h[n];

	/* copy deleted element to last place. This form the basis for
	 * heap sort
	 */
	h[n] = val;

	i = 1;
	j = i*2;

	while(j<n-1) {
		if(h[j+1] > h[j])
			j = j+1;
		if(h[i] < h[j]) {
			temp = h[i];
			h[i] = h[j];
			h[j] = temp;
			i = j;
			j = 2 * j;
		}
		else 
			break;
	}

	return val;
}

void insert_element_into_heap(int32_t h[], int32_t n)
{
	int32_t i = n;
	int32_t temp;

	/* assign temp last position, which is vacant */
	temp = h[i];

	while( i > 1 && temp > h[i/2]) {
		h[i] = h[i/2];
		i=i/2;
	}
	
	h[i] = temp;

}
