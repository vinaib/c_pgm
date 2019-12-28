/*
 * Find pairs from a given set whose sum is 8
 * [1,2,3,9] sum=8
 * [1,2,4,4] sum=8
 */

#include<stdio.h>
#include<stdbool.h>

#define NUM_ELEMENTS(arr) (sizeof(arr)/sizeof(arr[0]))

void test_pair(int arr[], int num_of_elements, int sum);
bool find_pairs_big_o_n_square(int arr[], int num_of_elements,int sum);
bool find_pairs_by_pair(int arr[], int num_of_elements, int sum);

int main(void)
{
	int arr_1[] = {1,2,3,4,5,6,9};
	int arr_2[] = {1,2,4,4,5,6,8};
	int sum = 10;

	test_pair(arr_1, NUM_ELEMENTS(arr_1), sum);
	
	test_pair(arr_2, NUM_ELEMENTS(arr_2), sum);

}

void test_pair(int arr[], int num_of_elements, int sum)
{
	bool ret;

#ifdef BIG_O_N_SQUARE
	ret = find_pairs_big_o_n_square(arr, num_of_elements, sum);
#else
	ret = find_pairs_by_pair(arr, num_of_elements, sum);
#endif

	if(ret)
		printf("found pair whose sum is %d\n", sum);
	else
		printf("not found pair for given %d sum\n", sum);
	
}

bool find_pairs_big_o_n_square(int arr[], int num_of_elements, int sum)
{
	int loop1 = 0;
	int loop2;
	int cal;
	bool result = false;

	/* nested for loop is O(n^2) */
	for(; loop1 < num_of_elements; loop1++) {
		for(loop2=loop1;loop2 < num_of_elements; loop2++) {
			cal = arr[loop1] + arr[loop2];
			if(cal == sum) {
				printf("(%d:%d) is %d + %d = %d Yes\n", loop1, loop2, arr[loop1], arr[loop2], sum);
				result = true;
			}
			else
				printf("(%d:%d) is %d + %d = %d no\n", loop1, loop2, arr[loop1], arr[loop2], sum);
		}
	}

	return result;
}

bool find_pairs_by_pair(int arr[], int num_of_elements, int sum)
{
	int min_idx = 0;
	int max_idx = num_of_elements - 1;
	int target_sum;
	bool ret = false;
	
	while(min_idx < max_idx)
	{
		target_sum = arr[min_idx] + arr[max_idx];

		if(target_sum < sum) {
			++min_idx;
			printf("++min_idx %d\n", min_idx);
		} else if(target_sum > sum) {
			--max_idx;
			printf("--max_idx %d\n", max_idx);
		}
		else {
			ret = true;

			printf("found pair %d %d (min_idx%d: max_idx%d)\n", 
					arr[min_idx], arr[max_idx],	min_idx, max_idx);

			/* find next pair: when pair is found increment min idx.
			 * Decrementing max_idx will miss finding second pair
			 * in set {1,2,4,4,5,6,8}
			 */
			++min_idx;
		}
	}

	return ret;
}
