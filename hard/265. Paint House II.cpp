// There are a row of n houses, each house can be painted with one of the k colors. 
// The cost of painting each house with a certain color is different. 
// You have to paint all the houses such that no two adjacent houses have the same color.

// The cost of painting each house with a certain color is represented by a n x k cost matrix.For example, 
// costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, 
// and so on... Find the minimum cost to paint all houses.

// Note:
// All costs are positive integers.



// Idea: 
// using the method of dynamic programming
// dp[i][j] as using j at i, the minimum cost
// dp[i][j] = min(dp[i][j], dp[i - 1][l] + cost[i][j]) for l != j

class Solution {
public:
	int minCostII(vector<vector<int>>& costs) {
		int n = costs.size(), res = INT_MAX;
		if (!n)
			return 0;
		int k = costs[0].size();
		vector<vector<int>> dp(n, vector<int>(k, INT_MAX));
		for (int i = 0; i<k; i++)
			dp[0][i] = costs[0][i];
		for (int i = 1; i<n; i++) {
			for (int j = 0; j<k; j++) {
				for (int l = 0; l<k; l++) {
					if (l != j)
						dp[i][j] = min(dp[i][j], dp[i - 1][l] + costs[i][j]);
				}
			}
		}
		for (int i = 0; i<k; i++)
			res = min(res, dp[n - 1][i]);
		return res;
	}
};