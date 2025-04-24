//stack -> LIFO and its implementation using an array....
//H/W ---> implement stack using single linkedList dynamic....

#include<iostream>
#include"singleLinkedList.cpp"
using namespace std;

class Stack
{
 LinkedList list;

 public:
   bool empty(); 
   void push(int d);
   int top();
   int pop();

};
bool Stack::empty()
{
    if(list.head==NULL)
    {
        return true;
    }
    return false;
}
void Stack::push(int d)
{
    list.insertAtHead(d);
}

int Stack::top()
{
  if(empty()==true)
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }  
    return list.head->data;
}

int Stack::pop()
{
    if(empty()==true)
    {
        cout<<"Stack underflow"<<endl;
        return -1;
    }
    int temp = list.head->data;
    list.head = list.head->next;
    return temp;
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    while(st.empty()!=true)
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}