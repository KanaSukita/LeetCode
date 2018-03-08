// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
// 
// Try to solve it in linear time/space.
// 
// Return 0 if the array contains less than 2 elements.
// 
// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.



// Idea:
// use bucket sort, since the max diff must be no smaller than (max-min)/(size-1) 
// the max diff must be the min of next bucket minus the previous max

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)
            return 0;
        int global_max = INT_MIN, global_min = INT_MAX;
        for(int n:nums){
            global_max = max(global_max, n);
            global_min = min(global_min, n);
        }
        double len = (global_max - global_min)*1.0 / (nums.size() - 1);
        if(!len)
            return 0;
        int n = floor((global_max - global_min) / len + 1);
        vector<int> bucket_max(n, INT_MIN);
        vector<int> bucket_min(n, INT_MAX);
        for(int i=0;i<nums.size();i++){
            int j = floor((nums[i] - global_min) / len);
            bucket_max[j] = max(bucket_max[j], nums[i]);
            bucket_min[j] = min(bucket_min[j], nums[i]);
        }
        int res = 0, last_max = bucket_max[0];
        for(int i=1;i<n;i++){
            if(bucket_min[i] != INT_MAX){
                res = max(res, bucket_min[i] - last_max);
                last_max = bucket_max[i];
            }
        }
        return res;
    }
};