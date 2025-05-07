//Merge Sort

#include<iostream>
using namespace std;
void merge(int arr[],int s,int e,int mid)
{
    int i = s;
    int j = mid+1;
    int k = 0;

    int temp[e+1];

    while(i<=mid && j<=e)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=e)
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    if(j>e)
    {
        while(i<=mid)
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
    }

    k = 0;
    for(int i = s;i<=e;i++)
    {
        arr[i] = temp[k];
        k++;
    }
}
void mergeSort(int arr[],int s,int e)
{
    if(s>=e)
    {
        return;
    }
    int mid = s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e,mid);
}
int main()
{
    int arr[6] = {18,13,17,15,20,14};

    cout<<"Array before sort"<<endl;
    for(int i = 0;i<6;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;

    mergeSort(arr,0,5);

    cout<<"Array after sort"<<endl;
    for(int i = 0;i<6;i++)
    {
        cout<<arr[i]<<"   ";
    }
    cout<<endl;
}