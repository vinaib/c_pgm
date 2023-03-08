#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>

#define ROW_3 		2
#define COLUMN_3 	2
#define COLUMNZ_3 	3

#define ROW_2		3
#define COLUMN_2 	4

void swap(int *ele1, int *ele2)
{
   *ele1 += *ele2;
   *ele2 = *ele1-*ele2;
   *ele1 = *ele1-*ele2;
}

// demonstrating of returning arrays
// returning local arrays is disaster, As its scope is lost once the function
// returns. So what is the solution for this?
// either create array dynamically or create static global array.
int *reverseArrRetLocal(int *arr, int sz)
{
   int i,j;

   //create new local array
   int revArr[sz];

   //copy elements from input arr to revArr
   memcpy((void*)revArr, (void*)arr, sizeof(int)*sz);

   for(i=0;i<sz;i++)
   {
      printf("%d ", revArr[i]);
   }

   printf("\n");

   for(i=0,j=sz-1;i<j;i++,j--)
   {
      swap(&revArr[i], &revArr[j]);
   }

   
   for(i=0;i<sz;i++)
   {
      printf("%d ", revArr[i]);
   }

   printf("\n");

   // return local array
   return revArr;
}

//returning dynamic arrays, but to ensure that arrays malloced must be freed
int *reverseArrRetDynamic(int *arr, int sz)
{
   int i,j;

   //create new array from heap
   int *revArr = (int *)malloc(sizeof(int)*sz);

   //copy elements from input arr to revArr
   memcpy((void*)revArr, (void*)arr, sizeof(int)*sz);

   for(i=0;i<sz;i++)
   {
      printf("%d ", revArr[i]);
   }

   printf("\n");

   for(i=0,j=sz-1;i<j;i++,j--)
   {
      swap(&revArr[i], &revArr[j]);
   }

   
   for(i=0;i<sz;i++)
   {
      printf("%d ", revArr[i]);
   }

   printf("\n");

   // return local array
   return revArr;

}

int doublePointerDemo(void)
{
	uint8_t arr_1d[12] = 
	{0x11, 0x22, 0x33, 0x44, 
	 0x55, 0x66, 0x77, 0x88, 
	 0x99, 0xaa, 0xbb, 0xcc};

	uint8_t arr_2d[2][3] = { {0x11, 0x22, 0x33}, {0x44, 0x55, 0x66}};

	uint8_t (*ptr_4)[COLUMN_3][COLUMNZ_3] = (uint8_t (*)[COLUMN_3][COLUMNZ_3])arr_1d;
	uint8_t (*ptr_3)[COLUMN_2] = (uint8_t (*)[COLUMN_2])arr_1d;
	uint8_t (*ptr_2)[3] = arr_2d;

	//uint8_t (*dptr)[4] = (uint8_t (*)[4])arr_1d; 
	uint8_t (*(*dptr));

	dptr = (uint8_t**)arr_1d;

	printf("size of arr_1d %ld\n", sizeof(arr_1d));
	printf("size of arr_2d %ld\n", sizeof(arr_2d));

	printf("contents of arr_1d\n");
	for(uint8_t i=0; i<sizeof(arr_1d); i++) {
		printf("%p - %#x\n", &arr_1d[i], arr_1d[i]);
	}

	printf("contents of arr_2d\n");
#if 0	
	for(uint8_t i=0;i<2;i++) {
		for(uint8_t j=0; j<3; j++) {
			printf("%p - %#x\n", &arr_2d[i][j], arr_2d[i][j]);
		}
	}
#endif
	uint8_t *parr = (uint8_t*)arr_2d;
	for(uint8_t i=0; i<sizeof(arr_2d); i++)
	{
		printf("%p - %#x\n", parr+i, *(parr+i));
	}

	printf("contents of ptr_4\n");
	for(uint8_t i=0; i<ROW_3; i++) 
		for(uint8_t j=0; j<COLUMN_3; j++)
			for(uint8_t k=0; k<COLUMNZ_3; k++)
			printf("%p - %#x\n", &ptr_4[i][j][k], ptr_4[i][j][k]);

	printf("contents of ptr_3\n");
	for(uint8_t i=0; i<ROW_2; i++) {
		printf("ROWWWWW %p\n", ptr_3+i);
		for(uint8_t j=0; j<COLUMN_2; j++) {
			printf("%p - %#x\n", &ptr_3[i][j], ptr_3[i][j]);
		}
	}

	printf("contents of dtpr\n");
	for(uint8_t i=0; i<3; i++) {
		printf("ROWWWWW %p\n", dptr+i);
		//for(uint8_t j=0; j<4; j++) {
		//	printf("%p - %#x\n", &dptr[i][j], dptr[i][j]);
		//}
	}
}

int *tgtSum(int *arr, int sum, int sz)
{
   int i,j;
   int found = 0;

   printf("%s: sz of arr %ld\n", __func__, sizeof(arr));

   // total time complexity is O(N square)
   for(i=0;i<sz;i++) //O(N)
   {
      for(j=i;j<sz;j++)    //O(N)
      {
         if((arr[i]+arr[j] == sum))
         {
            found = 1;
            // break: breaks only one level of loop in which it is
            break;
         }
      }
      // this is to break the i loop
      if(1 == found)
      {
         break;
      }
   }

   if(found)
   {
      int *res = (int*)malloc(sizeof(int)*2);

      printf("%d+%d = %d\n", arr[i], arr[j], sum);

      res[0] = arr[i];
      res[1] = arr[j];
      return res;
   }
   
   return NULL;
}

int main(int argc, char*argv[])
{
   int *resultArr;
   int intArr[] = {1,2,3,4,5,6};
   int i;
   int sum=10;
   
   if(argc==2)
   {
      sum = atoi(argv[1]);
   }

   printf("%s: sz of arr %ld\n", __func__, sizeof(intArr));

   resultArr = reverseArrRetDynamic(intArr, sizeof(intArr)/sizeof(int));

   for(i=0; i<sizeof(intArr)/sizeof(int); i++)
   {
      printf("%d ", resultArr[i]);
   }
   printf("\n");

   free(resultArr);

   resultArr = tgtSum(intArr, sum, sizeof(intArr)/sizeof(int));

   if(resultArr != NULL)
   {
      printf("%d %d", resultArr[0], resultArr[1]);

      free(resultArr);
   } 

   printf("\n");
}

