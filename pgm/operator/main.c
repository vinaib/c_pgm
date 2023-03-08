#include <stdio.h>
#include <limits.h>

int main(int argc, char *argv[])
{
   printf("size of long       %ld\n", sizeof(long));
   printf("size of long long  %ld\n", sizeof(long));
   printf("size of int        %ld\n", sizeof(int));
   printf("uint MAX limit     %u\n", UINT_MAX);
}
