#include<stdio.h>
#include<stdlib.h>

/* Converts to boolean */
#define BB(x) (!!x)

#define FEEDBACK_DATA(m,n) 		\
	{						\
		m[0] = ((n<<4) & 0xFFU);		\
		m[1] = (((n<<4) >> 8U) & 0xFFU);	\
		m[2] = (((n<<4) >> 16U) & 0xFFU);	\
		m[3] = (((n<<4) >> 24U) & 0xFFU);	\
	}

#define FEEDBACK_DATA_3(m,n) 		\
	{						\
		m[0] = ((n<<3) & 0xFFU);		\
		m[1] = (((n<<3) >> 8U) & 0xFFU);	\
		m[2] = (((n<<3) >> 16U) & 0xFFU);	\
		m[3] = (((n<<3) >> 24U) & 0xFFU);	\
	}
		
		
int main(int argc, char *argv[])
{
	int i = 10;
	char buff[4] = {0};
	char buff_3[4] = {0};
	int rate = 0;

	if(argc < 2)
	{
		FEEDBACK_DATA(buff, 48000);
		FEEDBACK_DATA_3(buff_3, 48000);
	}
	else 
	{
		rate = atoi(argv[1]);
		FEEDBACK_DATA(buff, rate);
		FEEDBACK_DATA_3(buff_3, rate);
	}

	printf("%d %d\n", i, BB(i));
	printf("%u %u %u %u\n", buff[0], buff[1], buff[2], buff[3]);
	printf("%x %x %x %x\n", buff[0], buff[1], buff[2], buff[3]);
	printf("%x %x %x %x\n", buff_3[0], buff_3[1], buff_3[2], buff_3[3]);
}
