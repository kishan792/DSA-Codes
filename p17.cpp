#include<bits/stdc++.h>
using namespace std;

int maxSubArrayLength1(vector<int> nums,int k)
{
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int maxLen = -1;

    while(right<nums.size())
    {
        while(left<=right && sum>k)
        {
            sum -=nums[left];
            left++;
        }

        if(sum == k)
        {
            maxLen = max(maxLen,right-left+1);
        }

        right++;

        if(right<nums.size())
        {
            sum+= nums[right];
        }
    }
    return maxLen;
}

int maxSubArrayLength(vector<int> nums,int k)
{
    int maxLen = -1;
    int sum = 0;
    map<int,int> prefix;

    for(int i = 0;i<nums.size();i++)
    {
        sum+=nums[i];

        if(sum==k)
        {
            maxLen = max(maxLen,i+1);
        }

        int rem = sum - k;

        if(prefix.find(rem)!=prefix.end())
        {
            int len = i - prefix[rem];
            maxLen = max(maxLen,len);
        }

        if(prefix.find(sum)==prefix.end())
        {
            prefix[sum] = i;
        }
    }
    return maxLen;
}

int main()
{
    vector<int> nums = {2,3,8,1,9};
    int k = 10;
    int len = maxSubArrayLength1(nums,k);
    cout<<"Max length : "<<len<<endl; 
}