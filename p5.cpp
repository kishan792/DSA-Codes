#include<iostream>
#include<vector>
using namespace std;

void rotateByOne(vector<int> &arr)
{
      int temp = arr[arr.size()-1];
        for(int i=arr.size()-1;i>0;i--)
        {
            arr[i] = arr[i-1];
        }
        
        arr[0] = temp;
    
}


void reverseArray(vector<int> &nums,int low,int high)
    {
        int i = low;
        int j = high -1;
        while(i<=j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }


void rotateByK(vector<int> &nums,int k)
{
    // k = k%arr.size();

    // for(int i = 0;i<k;i++)
    // {
    //     rotateByOne(arr);
    // }

    // Aprroach - 2 using space below code have TC - O(n)  sc -- O(n)...

    //  vector<int> temp(nums.size());

    //     k = k%nums.size();
    //    

    //     for(int i = 0;i<nums.size();i++)
    //     {
    //         int index = ((i+k))%nums.size();
    //         
    //         temp[index] = nums[i];
    //     }

//         for(int i = 0;i<nums.size();i++)
//         {
//             nums[i] = temp[i];
//         }

    //approach - 3 

     k = k%nums.size();

        reverseArray(nums,0,nums.size());

        reverseArray(nums,0,k);

        reverseArray(nums,k,nums.size());
}


int main()
{
  vector<int> arr = {1,2,3,4,5,6,7};
    

    rotateByK(arr,3);

    for(int i = 0;i<arr.size();i++)
    {
        cout<<arr[i]<<"  ";
    }


}