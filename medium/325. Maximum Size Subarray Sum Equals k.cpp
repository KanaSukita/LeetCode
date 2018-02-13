// Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

// Note:
// The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

// Example 1:
// Given nums = [1, -1, 5, -2, 3], k = 3,
// return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

// Example 2:
// Given nums = [-2, -1, 2, 1], k = 1,
// return 2. (because the subarray [-1, 2] sums to 1 and is the longest)



// Idea:
// using a hash map to store the index of a sum. e.g m[i] represenst from index 0 to m[i], the sum is i. when the current sum == k, it will always be the maximum length so far, otherwise, if we can find the index with m[sum - k], we can also try to update with i - m[sum - k]. btw, to ensure i - m[sum - k] will be the maximum possibilities, only update m[i] when the sum hasn't appear

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int cur = 0, res = 0;
        for(int i=0;i<nums.size();i++){
            cur += nums[i];
            if(cur == k)
                res = i + 1;
            if(m.count(cur - k))
                res = max(res, i - m[cur - k]);
            else if(!m.count(cur))
                m[cur] = i;
        }
        return res;
    }
};