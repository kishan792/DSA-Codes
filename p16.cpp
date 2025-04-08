#include<bits/stdc++.h>
using namespace std;
//bruteforce solution -- O(n3);
int maxSubArray1(vector<int> nums)
{
    int globalMax = 0;
    for(int s = 0;s<nums.size();s++)
    {
        for(int e = s;e<nums.size();e++)
        {
            int sum = 0;
            for(int i = s;i<=e;i++)
            {
                sum+=nums[i];
            }

            globalMax = max(sum,globalMax);
        }
    }

    return globalMax;
}


int maxSubArray2(vector<int> nums)
{
    int globalMax = INT_MIN;
    for(int s = 0;s<nums.size();s++)
    {
        int sum = 0;
        for(int e = s;e<nums.size();e++)
        {
            sum+=nums[e];
            globalMax = max(sum,globalMax);
        }
    }

    return globalMax;
}
int main()
{
    vector<int> nums = {2,1,-3,4,-1,2,1,-5,4};

    int maxSum = maxSubArray2(nums);
    cout<<"sub array max sum : "<<maxSum<<endl;
}