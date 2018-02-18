// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

// You are given a target value to search. If found in the array return its index, otherwise return -1.

// You may assume no duplicate exists in the array.



// Idea:
// use binary search to find the boundary
// rotate the array using %
// use binary again to find the value

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if(!n)
            return -1;
        int l = 0, r = n - 1;
        while(l < r){
            int m = (l + r) / 2;
            if(nums[m] > nums[r])
                l = m + 1;
            else 
                r = m;
        }
        int rot = l;
        l = 0;
        r = n-1;
        while(l <= r){
            int m = (l + r) / 2;
            int realmid=(m + rot) % n;
            if(nums[realmid] == target)
                return realmid;
            if(nums[realmid] < target)
                l = m + 1;
            else 
                r = m - 1;
        }
        return -1;
    }
};