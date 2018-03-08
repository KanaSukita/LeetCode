// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// 
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// 
// Find the minimum element.
//
// You may assume no duplicate exists in the array.



// Idea:
// use binary search, there will be 3 cases:
// nums[l] < nums[r], in this case, nums[l] is the minimum
// nums[m] > nums[r], in this case, l = m + 1 since the left part is still the rotated part,
// else r = m

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        while(left<right){
            if(nums[left]<nums[right])
                return nums[left];
            int middle = (left + right)/2;
            if(nums[middle]>nums[right])
                left = middle+1;
            else
                right = middle;
        }
        return nums[left];
    }
};s

