// Given a grid where each entry is only 0 or 1, find the number of corner rectangles.

// A corner rectangle is 4 distinct 1s on the grid that form an axis-aligned rectangle. Note that only the corners need to have the value 1. Also, all four 1s used must be distinct.

 

// Example 1:

// Input: grid = 
// [[1, 0, 0, 1, 0],
//  [0, 0, 1, 0, 1],
//  [0, 0, 0, 1, 0],
//  [1, 0, 1, 0, 1]]
// Output: 1
// Explanation: There is only one corner rectangle, with corners grid[1][2], grid[1][4], grid[3][2], grid[3][4].



// Idea:
// using the method of dp
// dp[i+1][j+1] as the result to i row and j col, the 0 row and 0 col in dp are set as initialization, when grid[i][j] == 1, dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j] + the sum that ends at grid[i][j], if grid[i][j] == 0, dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] - dp[i][j]

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        if(grid.empty())
            return 0;
        int res = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0)
                    dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j];
                else{
                    int temp = 0;
                    for(int k=0;k<i;k++){
                        for(int l=0;l<j;l++){
                            if(grid[k][j] == 1 && grid[i][l] == 1 && grid[k][l] == 1)
                                temp++;
                        }
                    }
                    dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + temp;
                }
            }
        }
        return dp[n][m];
    }
};