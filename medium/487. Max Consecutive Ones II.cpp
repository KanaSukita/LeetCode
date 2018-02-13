// Given a binary array, find the maximum number of consecutive 1s in this array if you can flip at most one 0.

// Example 1:
// Input: [1,0,1,1,0]
// Output: 4
// Explanation: Flip the first zero will get the the maximum number of consecutive 1s.
//    After flipping, the maximum number of consecutive 1s is 4.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000



// Idea:
// similar to the template
// use two pointers to represent the start and end of a subarray
// update d when r - l > d

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = 0, r = 0, cnt = 0, d = 0;
        while(r<nums.size()){
            if(nums[r++] == 0)
                cnt++;
            while(cnt > 1)
                if(nums[l++] == 0)
                    cnt--;
            d = max(r - l, d);
        }
        return d;
    }
};
