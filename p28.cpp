//QuickSort Sort

#include<iostream>
using namespace std;
int partion(int arr[],int s,int e)
{
    int pivot = arr[s];
    int i = s;
    int j = e;

    while(i<j)//O(n)
    {
        while(arr[i]<=pivot && i<=e-1)
        {
            //to find a greater element
            i++;
        }
        while(arr[j]>pivot && j>=s+1)
        {
            //to find a smaller element
            j--;
        }
        if(i<j)
        {
            //swap it.
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[s],arr[j]);
    return j;

}

void quickSort(int arr[],int s, int e)
{
    if(s>=e)
    {
        return;
    }
    int part = partion(arr,s,e);
    quickSort(arr,s,part-1);
    quickSort(arr,part+1,e);
}

int main()
{
    int arr[6] = {17,13,18,15,20,14};

    cout<<"Array before sort"<<endl;
    for(int i = 0;i<6;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;

    quickSort(arr,0,5);

    cout<<"Array after sort"<<endl;
    for(int i = 0;i<6;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}