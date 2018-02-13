// Given a string S and a string T, count the number of distinct subsequences of S which equals T.

// A subsequence of a string is a new string which is formed from the original string by deleting some(can be none) of the characters 
// without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

// Here is an example :
// S = "rabbbit", T = "rabbit"

// Return 3.



// Idea:
// General case 1: dp[i][j] = dp[i][j - 1] if t[i - 1] != s[j - 1];
// General case 2: dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] if t[i - 1] == s[j - 1];   ### with s[j - 1] or without
// Boundary case 1: dp[0][j] = 1 for all j;
// Boundary case 2: dp[i][0] = 0 for all positive i.

// hint : think about the subsequence minus the last element

class Solution {
public:
	int numDistinct(string s, string t) {
		int n = s.length();
		int m = t.length();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 0; i<n + 1; ++i)
			dp[0][i]++;
		for (int j = 1; j<n + 1; ++j) {
			for (int i = 0; i<m + 1; i++) {
				if (s[j - 1] == t[i - 1])
					dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
				else
					dp[i][j] = dp[i][j - 1];
			}
		}
		return dp[m][n];
	}
};