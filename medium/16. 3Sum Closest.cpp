// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

//     For example, given array S = {-1 2 1 -4}, and target = 1.

//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).



// Idea:
// first sort the array
// certain one position , then use two pointers

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX, n = nums.size(), res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2;i++){
            int l = i + 1, r = n - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target)
                    return target;
                if(abs(target - sum) < diff){
                    res = sum;
                    diff = abs(target - sum);
                }
                if(sum > target)
                    r--;
                else if(sum < target){
                    l++;
                }
            }
            while(nums[i] == nums[i+1])
                i++;
        }
        return res;
    }
};