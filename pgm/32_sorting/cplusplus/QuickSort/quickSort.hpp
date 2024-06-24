#ifndef __QUICKSORT_HPP__
#define __QUICKSORT_HPP__

#include <vector>

using namespace std;

void partition(vector<int>&arr, int start, int end); 

vector<int> quick_sort(vector<int> &arr);

#endif // __QUICKSORT_HPP__