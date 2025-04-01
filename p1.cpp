//Liner Search  --T.c is O(n);
#include<iostream>
using namespace std;
int linearSearch(int arr[],int size,int k)
{
    for(int i = 0;i<size;i++)
    {
        if(arr[i]==k)
            return i;
    }
    return -1;
}


int main()
{
    int arr[9] = {15,14,13,18,21,16,17,23,11};
    int size = 9;
    int k;

    cout<<"Enter the value of k"<<endl;
    cin>>k;

    int indx = linearSearch(arr,size,k);
    indx>=0?cout<<"Element found at index "<<indx<<endl :cout<<"Element not found"<<endl;


}