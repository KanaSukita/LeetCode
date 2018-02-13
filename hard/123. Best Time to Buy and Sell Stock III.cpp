// Say you have an array for which the ith element is the price of a given stock on day i.

// Design an algorithm to find the maximum profit.You may complete at most two transactions.

// Note:
// You may not engage in multiple transactions at the same time(ie, you must sell the stock before you buy again).



// Idea: 
// // f[k, ii] represents the max profit up until prices[ii] (Note: NOT ending with prices[ii]) using at most k transactions. 
// f[k, ii] = max(f[k, ii-1], prices[ii] - prices[jj] + f[k-1, jj]) { jj in range of [0, ii-1] }
//          = max(f[k, ii-1], prices[ii] + max(f[k-1, jj] - prices[jj]))
// f[0, ii] = 0; 0 times transation makes 0 profit
// f[k, 0] = 0; if there is only one price data point you can't make any money no matter how many times you can trade
// local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff) 的原因是后者可以直观地解释，
// 就是把上次的交易跟i天的合并；前者是因为如果最后一天赚不了钱， 则可以把之前一次交易分成两次

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() < 2)
			return 0;
		int n = prices.size(), global[n][3] = { 0 }, local[n][3] = { 0 };
		for (int i = 1; i < n; i++) {
			int diff = prices[i] - prices[i - 1];
			for (int j = 1; j <= 2; j++) {
				local[i][j] = max(global[i - 1][j - 1] + max(diff, 0), local[i - 1][j] + diff);
				global[i][j] = max(local[i][j], global[i - 1][j]);
			}
		}
		return global[n - 1][2];
	}
};
