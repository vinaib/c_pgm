#include<stdio.h>

char *reverse_str(char *string)
{
	return string;
}

int main(int argc, char *argv[])
{
	char *string = "Hello world";

	if(argc > 1)
		printf("Not using default input %s\n", argv[1]);

	string = "Hello universe";

	printf("reverse is %s\n", reverse_str(string));

	return 0;
}

