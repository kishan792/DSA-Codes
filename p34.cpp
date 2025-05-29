#include<iostream>
#define size 20
using namespace std;

class Heap
{
    int arr[size];
    int count;

    public:
        Heap()
        {
            count = 0;
        }

        void insertAtHeap(int d);
        void printHeap();
        void deleteFromHeap();
};

void Heap::printHeap()
{
    for(int i =1;i<=count;i++)
    {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

void Heap::insertAtHeap(int d)
{
    if(count==size-1)
    {
        return;
    }

    count++;
    arr[count] = d;

    int i = count;

    while(i>0)
    {
        int parent = i/2;

        if(parent>0 && arr[i]<arr[parent])
        {
            swap(arr[i],arr[parent]);
            i = parent;
        }
        else{
            return;
        }
    }
}

void Heap::deleteFromHeap()
{
    swap(arr[1],arr[count]);
    count--;

    int i = 1;
    while(i<=count)
    {
        int lc = 2*i;
        int rc = 2*i+1;

        int smallest  = i;

        if(lc<=count && arr[lc]<arr[smallest])
        {
            smallest = lc;
        }

        if(rc<=count && arr[rc]<arr[smallest])
        {
            smallest = rc;
        }

        if(i!=smallest)
        {
            swap(arr[i],arr[smallest]);
            i = smallest;
        }
        else{
            break;
        }
    }

}

int main()
{
    Heap hp;

    hp.insertAtHeap(50);
    hp.insertAtHeap(40);
    hp.insertAtHeap(30);
    hp.insertAtHeap(10);
    hp.insertAtHeap(8);
    hp.insertAtHeap(19);
    hp.insertAtHeap(7);

    hp.printHeap();

    hp.deleteFromHeap();

    hp.printHeap();
}