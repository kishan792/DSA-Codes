#include<bits/stdc++.h>
using namespace std;

int pivotElement(vector<int> nums)
{
    

    for(int i = 0;i<nums.size();i++)
    {
        int leftSum = 0;
        int rightSum = 0;
        if(i==0)
        {
            leftSum = 0;
        }
        else{
            for(int j = i-1;j>=0;j--)
            {
                leftSum+=nums[j];
            }
        }

        if(i==nums.size()-1)
        {
            rightSum = 0;
        }
        else{
            for(int j = i+1;j<nums.size();j++)
            {
                rightSum+=nums[j];
            }
        }

        if(leftSum==rightSum)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    vector<int> nums = {1,7,3,6,5,6};
    int indx = pivotElement(nums);

    cout<<"pivot index : "<<indx<<endl;
}