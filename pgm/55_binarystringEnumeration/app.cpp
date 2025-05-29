/**
 * @file app.cpp
 * @brief Generate Binary Strings Of Length N 
 * Given a number n, generate all possible binary strings of length n. 
 * Example  { "n": 3 }  
 * Output: 
 * ["000", "001", "010", "011", "100", "101", "110", "111"] 
 */


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

#define stringify(s) #s
#define xstringify(s) stringify(s)

void bsHelper(string s, int n)
{
   if(n == 0)
   {
      std::cout << s << '\n';
   }
   else
   {
      bsHelper(s+"0", n-1);
      bsHelper(s+"1", n-1);
   }
}

void bsHelper(vector<string>& s, int n)
{
   if(n == 0)
   {
      std::cout << s[0] << '\n';
   }
   else
   {
      //s
      bsHelper(s[n-1]+"0", n-1);
      bsHelper(s[n-1]+"1", n-1);
   }
}

vector<string> get_binary_strings(int n) 
{
   int size = pow(2,n);   
   vector<string> slate(size);

   std::cout << "vector size: " << size << '\n';

   //bsHelper("", n);

   bsHelper(slate, n);

   return {slate}; 
} 

void dsHelper(std::string s, int n)
{
   if(n == 0)
   {
      std::cout << s << '\n';
   }
   else
   {
      for(int i = 0; i < 10; i++)
      {
         dsHelper(s+to_string(i), n-1);
      }
   }
}

void get_decimal_strings(int n)
{
   dsHelper("", n);

   return;
}

int main(int argc, char *argv[])
{
   int length = 0;

   if(argc < 2)
   {
      length = 4;
   }
   else
   {
      length = atoi(argv[1]);
   }

   get_binary_strings(length);
   //get_decimal_strings(length);

   // string s {"abc"};
   // int d = 10;
   // std::cout << s + to_string(d) << '\n';
}
