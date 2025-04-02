#include<iostream>
#include<vector>
using namespace std;

 int singleNonDuplicate(vector<int>& nums) {
        int size = nums.size();
        if(size==1)
        {
            return nums[0];
        }

        if(nums[0]!=nums[1])
            return nums[0];
        
        if(nums[size-1]!=nums[size-2])
            return nums[size-1];

        int s = 1;
        int e = size-2;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1])
            {
                return nums[mid];
            }

            //eleminate a half--->
            else if((mid%2==0 && nums[mid]==nums[mid+1]) || (mid%2==1 && nums[mid]==nums[mid-1]))
            {
                //this will represent we are on left half....
                s = mid+1;
            }
            else
            {
                e = mid -1;
            }
        }
        return -1;
        
    }

    int main()
    {
        vector<int> nums = {1,1,2,3,3,4,4,8,8};
        cout<<singleNonDuplicate(nums)<<endl;

    }
