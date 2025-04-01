#include<iostream>
using namespace std;

bool binarySearch(int arr[3][4],int target,int row,int col)
{
    int s = 0;
    int e = (row*col)-1;

    while(s<=e)
    {
        int mid = s + (e-s) /2;

        int i = mid / col;
        int j = mid % col;

        if(arr[i][j]==target)
        {
            return true;
        }
        else if(arr[i][j]<target)
        {
            s = mid+1;
        }
        else {
            e = mid -1;
        }
    }
    return false;
}
int main()
{
    int arr[3][4] = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int row = 3;
    int col = 4;
    int target = 33;
    bool flag = binarySearch(arr,target,row,col);

    flag?cout<<"Element found"<<endl : cout<<"Element Not found"<<endl ;
}