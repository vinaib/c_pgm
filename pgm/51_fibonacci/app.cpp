#include <iostream>

int fib(int n)
{
   //std::cout << "n: " << n << "\n";

   if (n <= 1)
   {
      return n;
   }

   return fib(n - 1) + fib(n - 2);
}

int fibIterative(int n)
{
   int f = 0;
   int s = 1;
   int res = 0;
   

   for(int i = 1; i<n; i++)
   {
      res = f + s;
      f = s;
      s = res;
   }

   return res;
}

int main()
{
   int n = 8;

   std::cout << "nth Fibonacci number is: " << fib(8) << '\n';
   std::cout << "nth Fibonacci number is: " << fibIterative(8) << '\n';

   return 0;
}
