#ifndef __RB_HPP__
#define __RB_HPP__

class rb
{
   public:
      rb(int size);
      ~rb();

      int enqueue(int element);
      int dequeue();
      bool isFull();
      bool isEmpty();

   private:
      int m_size;
      int m_read = 0;
      int m_write = 0;
      bool m_full = 0;
      int *m_arr;
};

#endif // __RB_HPP__