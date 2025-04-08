//Time complexity --- > O(n)
#include<iostream>
using namespace std;

int sumArray(int prefixSum[],int i,int j)
{
    
    return prefixSum[j]-prefixSum[i-1];
}
int main()
{
    int arr[] = {5,1,4,6,8,3,7};
    int prefixSum[6];
    prefixSum[0] = arr[0];

    for(int i = 1;i<6;i++)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i];
    }

    int sum = sumArray(prefixSum,3,5);

    cout<<"sum : "<<sum<<endl;

    sum = sumArray(prefixSum,0,5);

    cout<<"sum : "<<sum<<endl;
}