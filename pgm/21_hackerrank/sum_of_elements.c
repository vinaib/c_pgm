#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include<errno.h>

int sum_of_elements() 
{

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n_ele = 0;
    int sum_of_ele = 0;
    int *arr;
    int idx;

    scanf("%d", &n_ele);

    arr = (int *)malloc(n_ele * sizeof(int));
    if(!arr) {
        printf("failed to allocate \n");
        return ENOMEM;
    }

    memset((void *)arr, 0, sizeof(arr));

    for(idx = 0; idx < n_ele; idx++) {
        scanf("%d", &arr[idx]);
        sum_of_ele += arr[idx];
    }

    printf("%d\n", sum_of_ele);

    free(arr);

    return sum_of_ele;
}

