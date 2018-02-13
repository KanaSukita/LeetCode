// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

// Example:

// Input: "babad"

// Output: "bab"

// Note: "aba" is also a valid answer.
 

// Example:

// Input: "cbbd"

// Output: "bb"



// Idea:
// two algorithms:
// 1. DP: initialize by dp[i][i] = true, and dp[i][i+1] = true  if s[i] = s[i+1] then traverse the string

// 2. there will be two kinds of center, a character or sth between two characters, then by expanding to the two ends and find the longest.

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int begin = 0, maxLen = 1;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i =0;i<n;i++)
            dp[i][i] = true;
        for(int i = 0; i< n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = true;
                begin = i;
                maxLen = 2;
            }
        }
        for(int len = 3;len <= n;len++){
            for(int i = 0;i<n-len+1;i++){
                int j = i + len -1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = true;
                    begin = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};