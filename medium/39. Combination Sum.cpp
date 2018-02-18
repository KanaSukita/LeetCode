// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

// The same repeated number may be chosen from C unlimited number of times.

// Note:
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
// [
//   [7],
//   [2, 2, 3]
// ]



// Idea:
// sort the array
// write a helper function to use backtracking to find the res, with a start index to avoid duplicate

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        addCom(res, candidates, cur, target, 0);
        return res;
    }
    void addCom(vector<vector<int>> &res, vector<int> candidates, vector<int> cur, int tar, int startID){
        if(tar==0){
            res.push_back(cur);
            return;
        }
        for(int i=startID;i<candidates.size() && tar>=candidates[i];i++){
            cur.push_back(candidates[i]);
            addCom(res, candidates, cur, tar - candidates[i], i);
            cur.pop_back();
        }
    }
};