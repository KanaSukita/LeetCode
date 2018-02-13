// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.

// Note:
// If n is the length of array, assume the following constraints are satisfied :

// 1 ¡Ü n ¡Ü 1000
// 1 ¡Ü m ¡Ü min(50, n)
// Examples :

// 	Input :
//	nums = [7, 2, 5, 10, 8]
//	m = 2

//	Output :
//	18

//	Explanation :
//	There are four ways to split nums into two subarrays.
//	The best way is to split it into[7, 2, 5] and [10, 8],
//  where the largest sum among the two subarrays is only 18.



// Idea:
// using the method of dp
// dp[n][k] as until n cut into k pieces, the maximum sum
// dp[n][k] = min(max(sum(0, n) - sum(0, i), dp[i][k - 1]))

class Solution {
public:
	int splitArray(vector<int>& nums, int m) {
		int n = nums.size();
		if (n == 2 && m == 2)
			return nums[0] > nums[1] ? nums[0] : nums[1];
		vector<vector<int>> dp(n, vector<int>(m, 0));
		dp[0][0] = nums[0];
		for (int i = 1; i<n; i++)
			dp[i][0] += dp[i - 1][0] + nums[i];
		for (int k = 1; k<m; k++) {
			for (int i = 0; i<n; i++) {
				int sum_l = dp[i][0];
				for (int j = 0; j<i; j++) {
					int temp = max(dp[j][k - 1], dp[i][0] - dp[j][0]);
					sum_l = min(sum_l, temp);
				}
				dp[i][k] = sum_l;
			}
		}
		return dp[n - 1][m - 1];
	}
};
