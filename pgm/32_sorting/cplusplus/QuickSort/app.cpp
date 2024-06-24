#include <vector>
#include "common.hpp"
#include "quickSort.hpp"

using namespace std;

int main()
{
   vector<int> arr{3,8,9,4,5,6,2,7,1};

   quick_sort(arr);
   printArr(arr);
 
}