#include<stdio.h>

#define INPUT_CRYSTAL_16MHZ 16000000

#define NDIV_MIN 1
#define NDIV_MAX 255
#define NDIV_OP_MIN_2MHZ 	2000000
#define NDIV_OP_MAX_150MHZ 	150000000

#define PDIV_MIN	2
#define PDIV_MAX	62
#define PDIV_INCREMENT	2

#define M_MULT_OP_MIN_275MHZ	275000000
#define M_MULT_OP_MAX_550MHZ	550000000

#define RATE_44KHZ	44100
#define RATE_48KHZ	48000
#define RATE_88KHZ	88200
#define RATE_96KHZ	96000

#define FRAME_WIDTH_32	32
#define FRAME_WIDTH_48	48
#define FRAME_WIDTH_64	64

#define CHANNELS_STEREO 2

#define MCLK_24_576_MHZ 	24576000
#define MCLK_22_5792_MHZ 	22579200
#define MCLK_23_2848_MHZ	23284800
#define MCLK_25_4016_MHZ	25401600
#define MCLK_18_432_MHZ		18432000
#define MCLK_23_040000_MHZ	23040000

#define REQ_MCLK MCLK_23_040000_MHZ

int main(int argc, char *argv[])
{
	int i = 0;
	int j = 0;
	int res_1 = 0;
	int res_2 = 0;
	int mult = 0;

	for(i=NDIV_MIN; i<=NDIV_MAX; i++)
	{
		if((INPUT_CRYSTAL_16MHZ % i) == 0)
		{
			res_1 = INPUT_CRYSTAL_16MHZ/i;
			printf("*****************************************************\n");
			printf("%d - %d \n", i, res_1);

			printf("MULT: \n");
			for(j=PDIV_MIN;j<=PDIV_MAX;j+=PDIV_INCREMENT)
			{
				if(((REQ_MCLK * j) % res_1) == 0)
				{
					mult = (REQ_MCLK * j) / res_1;
					printf("PDIV(%d) %d ", j, mult);
				}
			}

			printf("\n");
		}
	}

	return 0;
}
