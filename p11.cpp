//first occurance and last occurance in sorted array

#include<bits/stdc++.h>
using namespace std;
int firstOccurance(vector<int>& nums, int target)
    {
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                e = mid - 1;
            }
            else if(nums[mid]<target)
            {
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;

    }

    int lastOccurance(vector<int>& nums, int target)
    {
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                s = mid + 1;
            }
            else if(nums[mid]<target)
            {
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;

    }

    vector<int> searchRange(vector<int>& nums, int target) {

        int firstOcc = firstOccurance(nums,target);
        vector<int> ans = {-1,-1};
        
        if(firstOcc == -1)
        {
            return ans;
        }

        int lastOcc = lastOccurance(nums,target);

        ans[0] = firstOcc;
        ans[1] = lastOcc;

        return ans;
        
    }

    int main()
    {
        vector<int> nums = {5,7,7,8,8,10};
        int target = 8;

        vector<int> ans = searchRange(nums,target);

        cout<<"First Occurance  : "<<ans[0]<<endl;
        cout<<"last Occurance  : "<<ans[1]<<endl;

    }
