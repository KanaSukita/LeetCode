// Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, please find out a way you can make one square by using up all those matchsticks. You should not break any stick, but you can link them up, and each matchstick must be used exactly one time.
// 
// Your input will be several matchsticks the girl has, represented with their stick length. Your output will either be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.
// 
// Example 1:
// Input: [1,1,2,2,2]
// Output: true
// 
// Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
// Example 2:
// Input: [3,3,3,3,4]
// Output: false
// 
// Explanation: You cannot find a way to form a square with all the matchsticks.



// Idea:
// use the method of backtracking, first sort the array
// divide the sum to 4 pieces, if a sum plus a new num is smaller than the target, try it
// in each try, use s position index 

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4)
            return false;
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(sum % 4 != 0)
            return false;
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        return helper(nums, sums, 0, n, sum / 4);
    }
    bool helper(vector<int> &nums, vector<int> &sums, int pos, int &n, int target){
        if(pos == n)
            return (sums[0] == target && sums[1] == target && sums[2] == target);
        for(int j=0;j<4;j++){
            if(sums[j] + nums[pos] > target)
                continue;
            sums[j] += nums[pos];
            if(helper(nums, sums, pos + 1, n, target))
                return true;
            sums[j] -= nums[pos];
        }
        return false;
    }
};