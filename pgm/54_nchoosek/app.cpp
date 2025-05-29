#include <iostream>
#include <vector>

using namespace std;

// vector<vector<int>> find_combinations(int n, int k)
int find_combinations(int n, int k)
{
   // Write your code here.
   if( (n<=1) || (k==0) || (k==n) )
      return 1;
   else
      return find_combinations(n-1, k-1) + find_combinations(n-1, k);
}

vector<vector<int>> findCombinationsIterative(int n, int k)
{
   vector<vector<int>> r;

   for (int i=0; i<n; i++)
   {
      for(int j=i+1; j<n; j++)
      {
         r.push_back({i,j});
      }
   }

   return r;
}

int main(int argc, char *argv[])
{
   if(argc < 3)
   {
      std::cout << "improper output\n";
      return 0;
   }

   int n = atoi(argv[1]);
   int k = atoi(argv[2]);

   std::cout << find_combinations(n,k) << '\n';

   vector<vector<int>> a;

   a = findCombinationsIterative(n,k);

   for(auto i : a)
   {
      for(auto j: i)
      {
         std::cout << j << " ";
      }
      std::cout << '\n';
   }

   return 0;
}