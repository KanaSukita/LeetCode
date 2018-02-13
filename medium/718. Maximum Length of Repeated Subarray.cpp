// Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

// Example 1:
// Input:
// A: [1,2,3,2,1]
// B: [3,2,1,4,7]
// Output: 3
// Explanation: 
// The repeated subarray with maximum length is [3, 2, 1].



// Idea:
// use the method of dp, dp[i][j] as res for start at a[i] and b[j]
// if(a[i] == b[j])      dp[i][j] = dp[i+1][j+1] + 1
// else       dp[i][j] = 0

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size(), res = INT_MIN;
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(A[i] == B[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else dp[i][j] = 0;
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};