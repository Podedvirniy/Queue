#include <iostream>
#include <ctime>
using namespace std;
struct queue
{
 int size = 8;
 int Q[8];
 int head;
 int tail;
 void MAKENULL();
 int FRONT();
 void ENQUEUE(int x);
 void DEQUEUE();
};
int main()
{
 srand(time(NULL));
 queue q;
 q.MAKENULL();
 for (int i = 0; i < q.size; i++)
 {
  q.ENQUEUE(rand() % 10 );
 }
 q.DEQUEUE();
 q.DEQUEUE();
 q.ENQUEUE(9);
 while (q.head != q.tail)
 {
  cout << q.FRONT() << endl;
  q.DEQUEUE();
 }
}
void queue::MAKENULL()
{
 head = 0;
 tail = -1;
}
int queue::FRONT()
{
 return Q[head];
}
void queue::ENQUEUE(int x)
{
 if (tail == size)
 {
  cout << "Sorry, the queue is full" << endl;
 }
 else
 {
  Q[tail + 1] = x;
  tail++;
 }
}
void queue::DEQUEUE()
{
 if (head == tail) cout << "Queue is empty" << endl;
 else {
  int* tmp = new int[size];
  for (int i = 0; i < size - 1; i++)
  {
   tmp[i] = Q[i + 1];
  }
  for (int i = 0; i < size; i++)
  {
   Q[i] = tmp[i];
  }
  delete[] tmp;
  tail--;
 }
}

