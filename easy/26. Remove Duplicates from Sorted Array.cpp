// Given a sorted array, remove the duplicates in-place such that each element appear only once and return the new length.

// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

// Example:

// Given nums = [1,1,2],

// Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the new length.



// Idea:
// traverse the aray, if n > nums[i-1] updare nums[i++] 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int i=0;
        for(int n:nums){
            if(!i || n>nums[i-1])
                nums[i++]=c;
        }
        return i;
    }
};

