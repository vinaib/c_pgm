#include <iostream>

int powerof2(int k)
{
   std::cout << ">>> " << k << '\n';

   if( 0 == k)
   {
      return 1;
   }
   else
   {
      return 2 * powerof2(k-1);
   }
}

int optPowerof2(int k)
{
   std::cout << ">>> " << k << '\n';

   if( 0 == k)
   {
      return 1;
   }
   else if ( 1 == k)
   {
      return 2;
   }
   else
   {
      int odd = (k % 2);
      int power = (k / 2);

      if(odd)
      {
         return 2 * optPowerof2(power) * optPowerof2(power);
      }
      else
      {
         return optPowerof2(power) * optPowerof2(power);
      }
   }
}

int moreOptPowerof2(int n)
{
   std::cout << ">>> " << n << '\n';

   int result=0;
   if( 0 == n)
   {
      return 1;
   }
   else if( 1 == n)
   {
      return 2;
   }
   else 
   {
      if(n % 2)
      {
         // odd
         result = moreOptPowerof2(n/2);
         result = 2 * result * result;
         return result;
      }
      else
      {
         result = moreOptPowerof2(n/2);
         result = result * result;
         return result;
      }
   }
   return 0;
}

int main(int argc, char *argv[])
{
   int power = 5;

   if (argc >= 2)
   {
      power = atoi(argv[1]);
   }

   std::cout << "Power of 2: " << powerof2(power) << '\n';
   std::cout << "Power of 2: " << optPowerof2(power) << '\n';
   std::cout << "Power of 2: " << moreOptPowerof2(power) << '\n';
   

   return 0;
}