#include <stdio.h>


void printRecursive(int a)
{
   if(a == 0)
   {
      return;
   }
   else
   {
      printRecursive(a-1);
      printf("%d\n", a);
   }
}


int main(int argc, char *argv[])
{
   if (argc > 0)
   {
      printf("cmdline args %d\n", argc);
   }

   int a = 20;

   printRecursive(a);

   return 0;
}
