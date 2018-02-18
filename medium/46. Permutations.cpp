// Given a collection of distinct numbers, return all possible permutations.

// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]



// Idea:
// use the method of backtracking
// write a helper function, which includes a index parameter to avoid duplicate

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permu(nums, res, 0);
        return res;
    }
    void permu(vector<int> &nums, vector<vector<int>> &res, int ind){
        if(ind>=nums.size()){
            res.push_back(nums);
            return;
        }
		
		for (int i = ind; i < nums.size(); i++) {
		    swap(nums[ind], nums[i]);
		    permu(nums, res, ind+1);
		    swap(nums[ind], nums[i]);
		}
    }
};