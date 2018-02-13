// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit.You may complete at most k transactions.

// Note:
// You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).

// Credits :
//	  Special thanks to @Freezen for adding this problem and creating all test cases.



// Idea:
// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff)
// global[i][j] = max(local[i][j], global[i - 1][j])£¬

// global as until i day k transactions
// local as until i day k tranactions where sell the last one on i day

// hint : it's achievable to merge two transactions

class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		if (prices.empty())
			return 0;
		if (k >= prices.size())
			return solveMaxProfit(prices);
		int global[k + 1] = { 0 };
		int local[k + 1] = { 0 };
		for (int i = 0; i < prices.size() - 1; ++i) {
			int diff = prices[i + 1] - prices[i];
			for (int j = k; j >= 1; --j) {
				local[j] = max(global[j - 1] + max(diff, 0), local[j] + diff);
				global[j] = max(global[j], local[j]);
			}
		}
		return global[k];
	}
	int solveMaxProfit(vector<int> &prices) {
		int res = 0;
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] - prices[i - 1] > 0) {
				res += prices[i] - prices[i - 1];
			}
		}
		return res;
	}
};