#include<bits/stdc++.h>
using namespace std;
bool slidingWindow(vector<int> nums,int target,int k)
{
    int sum = 0;
    vector<int> ans;
    for(int i = 0;i<k;i++)
    {
        sum+=nums[i];
    }
    if(sum==target)
        return true;
    
    int left = 0,right = k;
    while(right<nums.size())
    {
        sum-=nums[left];
        sum+=nums[right];
        left++;
        right++;
        if(sum==target)
            return true;
    }
    return false;
}
int main()
{
    vector<int> nums ={1,3,1,3,5,3,6,7};
    int target = 5;
    int k = 3;

    slidingWindow(nums,target,k) ? cout<<"subarray present"<<endl : cout<<"subarray not present"<<endl;
}