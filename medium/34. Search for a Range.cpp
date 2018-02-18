// Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].



// Idea:
// use binary search twice to find the left and right

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        vector<int> res(2, -1);
        if(!nums.size())
            return res;
        while(l < r){
            int m = (l + r) / 2;
            if(nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        if(nums[l] != target)
            return res;
        else
            res[0] = l;
        r = nums.size();
        while(l < r){
            int m = (l + r) / 2;
            if(nums[m] <= target)
                l = m + 1;
            else
                r = m;
        }
        res[1] = l - 1;
        return res;
    }
};




