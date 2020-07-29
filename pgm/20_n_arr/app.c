#include<stdio.h>
#include<stdint.h>

#define ROW_3 		2
#define COLUMN_3 	2
#define COLUMNZ_3 	3

#define ROW_2		3
#define COLUMN_2 	4
int main(void)
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

	dptr = (uint8_t (*)[3][4])arr_1d;

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
