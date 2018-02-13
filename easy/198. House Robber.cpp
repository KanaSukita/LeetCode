// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.



// Idea:
// maintain two money as rob the current one and the one before

class Solution {
public:
    int rob(vector<int>& nums) {
        int mon1 = 0;
        int mon2 = 0;
        for(int i = 0;i< nums.size(); i++){
            if(i%2==0)
                mon1=max(mon1+nums[i],mon2);
            else
                mon2=max(mon1,mon2+nums[i]);
        }
        return max(mon1, mon2);
    }   
};