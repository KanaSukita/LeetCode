// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
// 
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
// 
// Example:
// Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).



// Idea:
// sort the envelopes and apply a dp
// dp[i] = max(dp[i], dp[j] + 1) for 0<=j<i and envelopes[j] can be placed in envelopes[i]

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size(), res = 0;
        sort(envelopes.begin(), envelopes.end(), [](pair<int, int> &a, pair<int, int>&b){
            return a.first < b.first || (a.first == b.first && a.second < b.second);});
        vector<int> dp(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};