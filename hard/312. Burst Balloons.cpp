//	Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst 
//	all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices 
//	of i. After the burst, the left and right then becomes adjacent.

//	Find the maximum coins you can collect by bursting the balloons wisely.

//	Note:
//	(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//	(2) 0 ¡Ü n ¡Ü 500, 0 ¡Ü nums[i] ¡Ü 100

//	Example :

//		Given[3, 1, 5, 8]

//		Return 167



// Idea:
// Consider all the subintervals with certain length
// dp[i][j] as ballons from i to j
// consider k as the last ballon to burst, then
// dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j])
// return dp[1][n]

// hint: Assume the last ballon to burst, the corresponding coins number is certain, then the total sum isit plus the intervals 
// in front and behind.

class Solution {
public:
	int maxCoins(vector<int>& nums) {
		int n = nums.size();
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
		for (int len = 1; len<n + 1; ++len) {
			for (int i = 1; i <= n - len + 1; ++i) {
				int j = i + len - 1;
				for (int k = i; k<j + 1; ++k)
					dp[i][j] = max(dp[i][j], nums[i - 1] * nums[k] * nums[j + 1] + dp[i][k - 1] + dp[k + 1][j]);
			}
		}
		return dp[1][n];
	}
};