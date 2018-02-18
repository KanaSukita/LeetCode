// Given a collection of numbers that might contain duplicates, return all possible unique permutations.

// For example,
// [1,1,2] have the following unique permutations:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]



// Idea:
// first sort the vector
// using the method of backtracking, write a helper function with start index

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        backtracking(0, nums.size(), nums, res);
        return res;
    }
    void backtracking(int i, int n, vector<int> nums, vector<vector<int>> & res){
        if(i == n - 1){
            res.push_back(nums);
            return;
        }
        for(int j = i; j<n; j++){
            if(nums[i] == nums[j] && i != j)
                continue;
            swap(nums[i],nums[j]);
            backtracking(i+1, n, nums, res);
        }
    }
};