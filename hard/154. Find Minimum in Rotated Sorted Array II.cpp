// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// 
// Find the minimum element.
// 
// The array may contain duplicates.



// Idea:
// use binary search, what's different is when nums[m] == nums[r], make l++ and r--

class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int l = 0, r = nums.size()-1;
        while(l < r){
            if(nums[l] < nums[r])
                break;
            int m = (l+r) / 2;
            if(nums[m] == nums[r]){
                l++;
                r--;
            }
            else if(nums[m] > nums[r])
                l = m + 1;
            else
                r = m;
        }
        return nums[l];
    }
};