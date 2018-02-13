// Given an array of non-negative integers, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// For example :
// Given array A = [2, 3, 1, 1, 4]

// The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

// Note :
//  	You can assume that you can always reach the last index.



// Idea:
// Use the method of greedy
// When index + nums[index] >= n - 1, meaning we can reach the end use one more jump
// else, we should jump the steps that can let us reach further for the next jump

class Solution {
public:
	int jump(vector<int>& nums) {
		int res = 0, index = 0;
		int n = nums.size();
		while (index < n - 1) {
			int jump = 1;
			for (int i = 2; i <= nums[index]; i++) {
				if (index + nums[index] >= n - 1) {
					jump = nums[index];
					break;
				}
				if (jump + nums[index + jump] <= i + nums[index + i])
					jump = i;
			}
			index += jump;
			res++;
		}
		return res;
	}
};