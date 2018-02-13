// Consider the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", 
// so s will look like this: "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".

// Now we have another string p.Your job is to find out how many unique non - empty substrings of p are present in s.
// In particular, your input is the string p and you need to output the number of different non - empty substrings of p in the string s.

// Note : p consists of only lowercase English letters and the size of p might be over 10000.



// Idea:
// using the method of dp,if bcdef is a valid substring, then cdef, def, ef, f are all valid
// if (p[i] == p[i - 1] || p[i - 1] = 'z' && p[i] == 'a')	len++;
// else		len = 1;

// dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);

class Solution {
public:
	int findSubstringInWraproundString(string p) {
		vector<int> dp(26, 0);
		int len = 0, res = 0;
		for (int i = 0; i<p.size(); i++) {
			if (i > 0 && (p[i] - p[i - 1] == 1 || (p[i] == 'a' && p[i - 1] == 'z')))
				len++;
			else
				len = 1;
			dp[p[i] - 'a'] = max(dp[p[i] - 'a'], len);
		}
		for (int d : dp)
			res += d;
		return res;
	}
};