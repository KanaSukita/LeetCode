// This is an extension of House Robber.

// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.



// Idea:
// use dp method twice from 0 to n-2 and from 1 to n-1

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(!n)
            return 0;
        if(n == 1)
            return nums[0];
        int mon1 = 0, mon2 = 0;
        for(int i=0;i<n-1;i++){
            int temp = mon1;
            mon1 = mon2;
            mon2 = max(temp + nums[i], mon2);
        }
        int mon3 = 0, mon4 = 0;
        for(int i=1;i<n;i++){
            int temp = mon3;
            mon3 = mon4;
            mon4 = max(temp + nums[i], mon4);
        }
        return max(mon2, mon4);
    }
};






