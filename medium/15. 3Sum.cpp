// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note: The solution set must not contain duplicate triplets.

// For example, given array S = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]



// Idea:
// first sort the array, certain one position and use two pointers from left and right to find the res

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++){
            if(nums[i] > 0)
                break;
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0)
                    r--;
                else if(sum < 0)
                    l++;
                else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(nums[l] == nums[l+1])
                        l++;
                    while(nums[r] == nums[r-1])
                        r--;
                    l++;
                    r--;
                }
                while(nums[i] == nums[i+1])
                    i++;
            }
        }
        return res;
        
    }
};