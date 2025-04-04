//81. Search in Rotated Sorted Array - 2

#include<iostream>
#include<vector>
using namespace std;

 bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid]==target)
            {
                return true;
            }

            if(nums[s] == nums[mid] && nums[mid]==nums[e])
            {
                s = s+1;
                e = e -1;
                continue;
            }
            if(nums[s]<=nums[mid])
            {
                //left part is sorted and apply binary search here
                if(nums[s]<=target && target <=nums[mid])
                {
                    e = mid-1;
                }
                else
                {
                    s = mid+1;
                }

            }
            else
            {
                //right part is sorted and apply binary search here
                if(nums[mid]<=target && target<=nums[e])
                {
                    s=mid+1;
                }
                else
                {
                    e = mid-1;
                }
            }
        }
        return false;
    }

    int main()
    {
        vector<int> nums = {1,0,1,1,1};
        int target = 0;
        search(nums,target)==false?cout<<"Element not found"<<endl : cout<<"Element found : "<<endl;

    }
