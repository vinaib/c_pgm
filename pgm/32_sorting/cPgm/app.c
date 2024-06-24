#include<stdint.h>
#include<stdio.h>
#include<stdlib.h>

////// Signature 
/*
 * Function: 
 * Number of passes:
 * Number of comparisons:
 * Number of swaps:
 * Adaptive:
 * stable:
 * Extra Memory:
 */
////// End of signature
#define DBG_SWP
#define DBF_BBL_SORT		

void swap(int32_t *x, int32_t *y)
{
#ifdef DBG_SWP	
	printf("swap(%d %d) -> ", *x, *y);
#endif
   // using this approach, if x and y are same then both x and y will be zero. 
   // so this method is not best to use.
   // please use swap with temp variable
#ifdef SWAP_BY_ADD
	*x = *x + *y;
	*y = *x - *y;
	*x = *x - *y;
#else
   int32_t temp;
   temp = *x;
   *x = *y;
   *y = temp;
#endif
#ifdef DBG_SWP	
	printf("(%d %d)\n", *x, *y);
#endif
}

void print_array(int32_t a[], int32_t sz)
{
	int32_t i=0;

	for(i=0;i!=sz;i++)
		printf("%d ", a[i]);

	printf("\n");
}

/*
 * Function: 					bubble sort   
 * Number of passess(n):		n - 1
 * Number of Comparisions:  	n(n-1)/2
 * Number of Swaps:				n(n-1)/2
 * Adaptive: 					adaptive, by using flag
 * stable:						yes
 * Extra Memory:
 */

void bubble_sort(int32_t *a, int32_t n)
{
	int32_t i = 0, j = 0;
	int32_t flag;

	printf("%s:\n", __FUNCTION__);
	print_array(a, n);

	for(j = 0; j < n-1; j++) {
		flag = 0;
#ifdef DBF_BBL_SORT		
		printf("Pass %d:\n", j);
#endif
		for(i = 0; i < n - 1 - j; i++) {
			if(a[i] > a[i+1]) {
				swap(&a[i], &a[i+1]);
				flag = 1;
			}
#ifdef VDBF_BBL_SORT		
			printf("%d ",a[i]);
#endif
		}
#ifdef VDBF_BBL_SORT		
		printf("\n");
#endif

		if(!flag)
			break;
	}
	print_array(a, n);
}


/*
 * Function: 					Insertion sort
 * Number of passes(n):			n - 1 
 * Number of comparisons:		n(n - 1)/2
 * Number of swaps:				n(n - 1)/2
 * Adaptive:					Yes
 * stable:						Yes
 * Extra Memory:				
 */
void insertion_sort(int32_t *a, int32_t n)
{
	int32_t i,j,x;

	printf("%s:\n", __FUNCTION__);
	print_array(a, n);

	for(i = 1; i<n; i++) {
		j = i-1;
		x = a[i];	// element to insert

		while(j>-1 && a[j] > x) {
			a[j+1] = a[j];
			j--;
		}

		/* insert x */
		a[j+1] = x;
	}
	print_array(a, n);
}

/*
 * Function: 					Selection sort
 * Number of passes(n):			n - 1
 * Number of comparisons:
 * Number of swaps:
 * Adaptive:
 * stable:
 * Extra Memory:
 */
void selection_sort(int32_t *a, int32_t n)
{
	int32_t i,j,min_idx;

	printf("%s:\n", __FUNCTION__);

	print_array(a, n);

	/* for n elements , n-1 passess. so outer loop to n-1 times 
	 * Outer loop: n-1 passes, also points to position the next smallest
	 * element to be swapped with.
	 */
	for(i=0; i<n-1; i++) {
		/* after inner loop traversal, min_idx points to smallest element 
       */
		for(j=min_idx=i; j<n; j++) {
			if(a[j] < a[min_idx]) {
				min_idx = j;
			}
		}

		/* do not swap if i is already pointed to smallest element */
		if(i!=min_idx) {
			swap(&a[i], &a[min_idx]);
		}
	}

	print_array(a, n);
}

/*
 * Function: 				quick_sort or partition_exchg or selection_exch
 * Number of passes:
 * Number of comparisons:
 * Number of swaps:
 * Adaptive:
 * stable:
 * Extra Memory:
 */

int32_t partition(int32_t a[], int32_t l, int32_t h)
{
	int32_t pivot = a[l];
	int32_t i=l, j=h;

	do {
		do{i++;}while(a[i]<=pivot);

		do{j--;}while(a[j]>pivot);

		if(i<j)
			swap(&a[i], &a[j]);

	}while(i<j);
	
	if(l!=j)		
		swap(&a[l], &a[j]);

	return j;
}

void quick_sort(int32_t a[], int32_t l, int32_t h)
{
	int32_t j;

	if(l < h) {
		j = partition(a, l, h);
		quick_sort(a, l, j);
		quick_sort(a, j+1, h);
	}
}

/*
 * Function: 				Merge sort
 * Number of passes:
 * Number of comparisons:
 * Number of swaps:
 * Adaptive:
 * stable:
 * Extra Memory:
 */
void merge_2_lists()
{
	int32_t a[] = {2,10,18,20,23};
	int32_t b[] = {4,9,19,25,31,35,45};
	int32_t c[15] = {0};

	int32_t i = 0,j = 0,k = 0;
	int32_t a_sz = sizeof(a)/sizeof(a[0]);
	int32_t b_sz = sizeof(b)/sizeof(b[0]);
	int32_t c_sz = sizeof(c)/sizeof(c[0]);

	printf("a_sz %d b_sz %d c_sz %d\n", a_sz, b_sz, c_sz);

	do {
		if(a[i] < b[j]) {
			c[k++] = a[i++];
		}
		else {
			c[k++] = b[j++];
		}
	}while(i<a_sz && j<b_sz);

	while(i < a_sz) { 
		c[k++] = a[i++]; 
	}

	while(j < b_sz) { 
		c[k++] = b[j++]; 
	}

	for(i=0; i<c_sz; i++)
		printf("%d ", c[i]);

	printf("\n");
}

void merge(int32_t a[], int32_t l, int32_t mid, int32_t h)
{
	int32_t i,j,k;
	int32_t b[100];

	i=l;
	j=mid+1;
	k=l;

	printf("%s l=%d mid=%d h=%d\n", __func__, l, mid, h);

	while(i<=mid && j<=h) {
		if(a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	for(;i<=mid;i++)
		b[k++] = a[i];
		
	for(;j<=h;j++)
		b[k++] = a[j];
	
	for(i=l; i<=h; i++) 
		a[i] = b[i];
}

void merge_sort(int32_t a[], int32_t n)
{
	int32_t p,l,h,mid,i;

	print_array(a, n);

	for(p=2;p<=n;p=p*2) {
		for(i=0;i+p-1<=n;i=i+p) {
			l = i;
			h = i+p-1;
			mid = (l + h)/2;
			merge(a,l,mid,h);
		}
	}
	if(p/2 < n)
		merge(a, 0, p/2-1, n);

	print_array(a, n);
}

int32_t main(int32_t argc, char *argv[])
{
	int32_t s_arr[] = {5,10,15,40,30,15,20};
	int32_t u_arr[] = {11, 13, 7, 2, 6, 9, 5, 4, 10, 3};
	int32_t q_arr[] = {11, 13, 7, 2, 6, 9, 5, 4, 10, 3, INT32_MAX};
	
	int32_t i;
	int32_t ch = 0;
	int32_t s_sz = (sizeof(s_arr)/sizeof(u_arr[0]));
	int32_t u_sz = (sizeof(u_arr)/sizeof(u_arr[0]));
	int32_t q_sz = (sizeof(q_arr)/sizeof(q_arr[0]));

	if(argc > 1)  {
		ch = atoi(argv[1]);
		if(ch <= 0) {
			printf("Enter proper choice....\n");
			goto end;
		}
	}

	switch(ch) {
		case 1: bubble_sort(u_arr, u_sz); 		break;
		case 2: insertion_sort(u_arr, u_sz); 	break;
		case 3: selection_sort(u_arr, u_sz); 	break;
		case 4: quick_sort(q_arr, 0, q_sz-1);	
				print_array(q_arr, q_sz);
				break;
		case 5: merge_sort(u_arr, u_sz);		break;				
	}


end:
	return 0;
}
