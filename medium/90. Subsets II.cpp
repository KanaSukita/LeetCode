// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
// 
// Note: The solution set must not contain duplicate subsets.
//
// For example,
// If nums = [1,2,2], a solution is:
// 
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]



// Idea:
// first sort the array
// write a helper function to store, if the new element has appeared before, just add it to the previous last index to the last index of the current res, otherwise, traverse all the indices of res and add this element

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        helper(nums, 0, res);
        return res;
    }
    void helper(vector<int> &nums, int start, vector<vector<int>> &res){
        vector<int> temp;
        res.push_back(temp);
        int last_idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            int start_idx = 0;
            if (i > 0 && nums[i] == nums[i-1]) {
                start_idx = last_idx;
            }
            int cur_sz = res.size();
            last_idx = cur_sz;
            for (int j = start_idx; j < cur_sz; j++) {
                vector<int> one = res[j];
                one.push_back(nums[i]);
                res.push_back(one);
            }
        }
    }
};