#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int gt_a = 0, gt_o = 0, gt_e = 0;

  for(int i=1; i<=n; i++) {
      for(int j=i+1; j<=n; j++) {        
        if(((i & j) < k) && (gt_a < (i & j))) {
            gt_a = i & j;
        }
        if((i | j )< k && (gt_o < (i | j))) {
            gt_o = i | j;
        }
        if(((i ^ j) < k) && (gt_e < (i ^ j))) {
            gt_e = i ^ j;
        }
      }
  }
  printf("%d\n%d\n%d\n", gt_a, gt_o, gt_e);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    if(n < 2 || n > 1000) 
        return -1;

    if(k < 2 || k > n) 
        return -1;

    calculate_the_maximum(n, k);
 
    return 0;
}
