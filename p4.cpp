//Second max -- tc = O(n)

#include<iostream>
using namespace std;
int secondMax(int arr[],int size)
{
    int max = -1;
    int s_max = -1;

    for(int i = 0;i<size;i++)
    {
       if(arr[i]>max)
       {
        s_max = max;
        max = arr[i];
       } 
       else if(arr[i]<max && arr[i]>s_max)
       {
        s_max = arr[i];
       }
    }
    return s_max;
}


int main()
{
    int arr[9] = {10,5,10};
    int size = 3;
    

    int s_max = secondMax(arr,size);
    cout<<"second max : "<<s_max<<endl;


}



// bool check(vector<int>& nums) {
//         int count = 0;
//         for(int i = 0;i< nums.size();i++)
//         {
//             if(nums[i]>nums[(i+1)%nums.size()])
//             {
//                 count++;
//             }
//         }