
// <-----Del   10 , 20, 30 , 40  <-----push

#include<iostream>
#include<queue>
using namespace std;
class Stack
{
    queue<int> q;
    public:
        void push(int d);
        int pop();
        bool empty();
        int top();
};

void Stack::push(int d)
{
    q.push(d);
}
int Stack::top()
{
    if(empty()==true)
    {
        return -1;
    }
     return q.back();
}
bool Stack::empty()
{
    return q.empty();
}

// <-----Del   40 , 10, 20 , 30<-----push
//tem = 40;
//all element are unique --- frontelement != back element


//q.size() ---> return the size of queue

int Stack::pop()
{
    int temp = q.back();
    int s = q.size();

    for(int i = 1;i<s;i++)
    {
        q.push(q.front());
        q.pop();
    }
    q.pop();

    return temp;
}

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // cout<<"Top Element : "<<st.top()<<endl;
    // st.pop();
    // cout<<"Top Element : "<<st.top()<<endl;

    while(st.empty()!=true)
    {
        cout<<st.top()<<endl;
        st.pop();
    }

}