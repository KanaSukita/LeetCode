// Your are given an array of positive integers nums.

// Count and print the number of (contiguous) subarrays where the product of all the elements in the subarray is less than k.

// Example 1:
// Input: nums = [10, 5, 2, 6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are: [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6].
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
// Note:
//
// 0 < nums.length <= 50000.
// 0 < nums[i] < 1000.
// 0 <= k < 10^6.



// Idea:
// first idea: dp where dp[i] as the result that ends at index i, TLE
// second idea: two pointers, find a window that satisfies the requirements and and the length to the result

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int res = 0, start = 0, end = 0, cur = 1;
        while(end < nums.size()){
            cur *= nums[end++];
            while(cur >= k)
                cur /= nums[start++];
            res += end - start;
        }
        return res;
    }
};