#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

class queue
{
   public:
      queue(int size);
      ~queue();
      int enqueue(int element);
      int dequeue();
      bool isEmpty();
      bool isFull();
   private:
      int m_size;
      int m_front = -1;
      int m_rear = -1;
      int *m_arr = nullptr;
};
#endif // __QUEUE_HPP__