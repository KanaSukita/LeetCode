// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

// Example:

// nums = [1, 2, 3]
// target = 4

// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)

// Note that different sequences are counted as different combinations.

// Therefore the output is 7.



// Idea:
// using the method of dp, dp drom 0 to target, dp[target] means the res for target
// when a element in nums n < i, dp[i] += dp[i-n]

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(nums.empty())
            return 0;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int i=1;i<=target;i++){
            for(auto n : nums){
                if(i >= n)
                    dp[i] += dp[i-n];
            }
        }
        return dp[target];
    }
};

