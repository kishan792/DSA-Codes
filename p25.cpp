//Queue  --> FIFO -> implementing using array
//Queue -> STL -> #include<queue> is dynamic in nature
//instertion and deletion take place from different end.
/*
    push -> to insert element in queue
    pop() -> to remove the element
    front() -> to print the front element
    back()-> to print back element
    size() -> to get size of the queu
    empty() -> to chck queue is empty or not
    full() -> to check queue is full or not.
*/

#include<iostream>
#define size 10
using namespace std;

class Queue
{
    int arr[size];
    int count;

    public:
        Queue()
        {
            count = -1;
        }

        bool empty();
        bool full();
        void push(int d);
        int front();
        int back();
        int pop();
};

bool Queue::empty()
{
    if(count==-1)
    {
        return true;
    }
    return false;
}

bool Queue::full()
{
    if(count==size-1)
    {
        return true;
    }
    return false;
}

void Queue::push(int d)
{
    if(full()==true)
    {
        cout<<"Queue Overflow"<<endl;
        return;
    }

    count++;
    arr[count] = d;
    return;
}

int Queue::front()
{
    if(empty()==true)
    {
        cout<<"Queue underflow"<<endl;
        return -1;
    }

    return arr[0];
}
int Queue::back()
{
    if(empty()==true)
    {
        cout<<"Queue underflow"<<endl;
        return -1;
    }

    return arr[count];
}

int Queue::pop()
{
  if(empty()==true)
  {
    cout<<"Queue underflow"<<endl;
    return -1;
  }  
  int temp  = arr[0];
  for(int i = 0;i<count;i++)
  {
    arr[i] = arr[i+1];
  }
  count--;
  return temp;
}

int main()
{
    Queue q;
    
}