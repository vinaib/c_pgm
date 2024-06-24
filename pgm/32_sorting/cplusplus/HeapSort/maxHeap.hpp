#ifndef __MAXHEAP_HPP__
#define __MAXHEAP_HPP__

#include <vector>

using namespace std;

class maxHeap
{
   public:
      maxHeap();
      ~maxHeap();
      void insert(int element);
      int extract();
      int extract2();
      void heapify();
      void sort();
      void print() const;

   private:
      std::vector<int> m_arr;
};

#endif // __MAXHEAP_HPP__