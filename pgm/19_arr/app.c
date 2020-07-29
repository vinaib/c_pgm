#include<stdio.h>
#include<stdint.h>

#define MIN_NUMBER -127
#define THRESHOLD 2
#define ZERO_ELEMENT 0
#define ONE_ELEMENT	1

int8_t find_second_largest(uint8_t *arr, int n_ele)
{
	int8_t i = 0;
	int8_t first = MIN_NUMBER;
	int8_t second = MIN_NUMBER;

	if(n_ele < THRESHOLD) 
		return -1;

	for(i=0; i<n_ele; i++) {
		if(arr[i] > first) {
			second = first;
			first = arr[i];
		}

		if(arr[i] != first && arr[i] > second) {
			second = arr[i];
		}
	}

	return second;
}

void reverse_arr(int8_t *arr, int n_ele)
{
	uint8_t i = 0;
	uint8_t j = n_ele - 1;

	if(n_ele == ZERO_ELEMENT || n_ele == ONE_ELEMENT) {
		printf("not enough elements\n");
		return;
	}

	for(; i<j; i++, j--) {
		arr[i] = arr[i] + arr[j];
		arr[j] = arr[i] - arr[j];
		arr[i] = arr[i] - arr[j];
	}
}

void display_arr(int8_t *arr, int n_ele) 
{
	for(uint8_t i = 0; i < n_ele; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void arr_negative_index(int8_t *arr, int n_ele)
{
	printf("%d %d\n", arr[-1], arr[-2]);
}

void print_arr_in_reverse(int8_t *arr, int n_ele)
{

	for(uint8_t i = 0; i < n_ele ; i++) 
		printf("%d ", *(arr-i));

	printf("\n");
}

int main(void)
{
	int8_t arr[] = {-1, 7, 1, 34, 18};

	int8_t ele = find_second_largest(arr, sizeof(arr)/sizeof(int8_t));

	printf("second largest element is %d\n", ele);

	reverse_arr(arr, sizeof(arr)/sizeof(int8_t));

	display_arr(arr, sizeof(arr)/sizeof(int8_t));

	reverse_arr(arr, sizeof(arr)/sizeof(int8_t));

	display_arr(arr, sizeof(arr)/sizeof(int8_t));

	arr_negative_index(&arr[0], sizeof(arr)/sizeof(int8_t));

	print_arr_in_reverse(
			(arr+((sizeof(arr)/sizeof(int8_t)) - 1)),
			sizeof(arr)/sizeof(int8_t) );
}
