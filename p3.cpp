//check sorted or not -->>

#include<iostream>
using namespace std;
bool checkSorted(int arr[],int size)
{
   for(int i = 1;i<size;i++)
   {
    if(arr[i]<arr[i-1])
        return false;
   } 
   return true;
}


int main()
{
    int arr[9] = {10,20,30,28,50,60,70,80,90};
    int size = 9;
    
    checkSorted(arr,size)?cout<<"Array is sorted "<<endl :cout<<"Unsorted Array"<<endl;

}