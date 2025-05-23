//33. Search in Rotated Sorted Array

#include<iostream>
#include<vector>
using namespace std;

 int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid]==target)
            {
                return mid;
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
        return -1;
    }

    int main()
    {
        vector<int> nums = {4,5,6,7,0,1,2};
        int target = 0;
        search(nums,target)==-1?cout<<"Element not found"<<endl : cout<<"Element found : "<<endl;

    }
