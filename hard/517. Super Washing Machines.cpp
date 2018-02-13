// You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.

// For each move, you could choose any m(1 ≤ m ≤ n) washing machines, and pass one dress of each washing machine to one of its adjacent 
// washing machines at the same time .

// Given an integer array representing the number of dresses in each washing machine from left to right on the line, you should find the 
// minimum number of moves to make all the washing machines have the same number of dresses.If it is not possible to do it, return -1.

// Example 1

// Input : [1, 0, 5]

//	Output : 3

//	Explanation :
//		1st move : 1     0 <-- 5 = >    1     1     4
//		2nd move : 1 <-- 1 <-- 4 = >    2     1     3
//		3rd move : 2     1 <-- 3 = >    2     2     2
//	Example2

//	Input : [0, 3, 0]

//	Output : 2

//	Explanation :
//		1st move : 0 <-- 3     0 = >    1     2     0
//		2nd move : 1     2 --> 0 = >    1     1     1
//	Example3

//	Input : [0, 2, 0]

//	Output : -1

//	Explanation :
//		It's impossible to make all the three washing machines have the same number of dresses. 

//	Note :
//	The range of n is[1, 10000].
//	The range of dresses number in a super washing machine is[0, 1e5].



// Idea:
// 思路为对每一台机器进行判断，从左向右进行检索，判断需要经过他的衣服的数量。比如，已经有5件衣服需要经过第i台机器进行传递，
// 同时这台机器本身又溢出了2件衣服，那么就需要传递7件衣服，共计7步。然后用一个变量实时记录最大值即可。

// 通过对本身跟avg的大小可以决定流向

class Solution {
public:
	int findMinMoves(vector<int>& machines) {
		int total = 0;
		int n = machines.size();
		for (auto m : machines)
			total += m;
		if (total%n || !n)
			return -1;
		int avg = total / machines.size(), res = 0;
		vector<int> dp(n, 0);
		for (int i = 0; i<n - 1; i++) {
			if (machines[i]>avg) {
				dp[i] += machines[i] - avg;
				machines[i + 1] += machines[i] - avg;
				machines[i] = avg;
				res = max(res, dp[i]);
			}
			else {
				dp[i + 1] = avg - machines[i];
				machines[i + 1] -= avg - machines[i];
				machines[i] = avg;
				res = max(res, dp[i + 1]);
			}
		}
		return res;
	}
};