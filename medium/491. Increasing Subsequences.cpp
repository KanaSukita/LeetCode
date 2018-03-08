// Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
// 
// Example:
// Input: [4, 6, 7, 7]
// Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]



// Idea:
// use backtracking, with a set to store the the numbers that has appeared, if the number has appeared, skip it

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        helper(nums, temp, 0, res);
        return res;
    }
    void helper(vector<int>& nums, vector<int> &temp, int ind, vector<vector<int>> &res){
        if(temp.size() >= 2)
            res.push_back(temp);
        unordered_set<int> st;
        for(int i = ind; i < nums.size(); i++){
            if (!temp.empty() && temp.back() > nums[i] || st.count(nums[i])) 
                continue;
            temp.push_back(nums[i]);
            st.insert(nums[i]);
            helper(nums, temp, i + 1, res);
            temp.pop_back();
        }
    }
};