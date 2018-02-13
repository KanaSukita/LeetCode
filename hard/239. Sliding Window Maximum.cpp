// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right.You can only see the k numbers in the window.Each time the sliding window moves right by one position.

// For example,
// Given nums = [1, 3, -1, -3, 5, 3, 6, 7], and k = 3.

// Window position                Max
// -------------- - ---- -
// [1  3 - 1] - 3  5  3  6  7       3
// 1[3 - 1 - 3] 5  3  6  7       3
// 1  3[-1 - 3  5] 3  6  7       5
// 1  3 - 1[-3  5  3] 6  7       5
// 1  3 - 1 - 3[5  3  6] 7       6
// 1  3 - 1 - 3  5[3  6  7]      7



// Idea:
// first though:
// using priority queue, but in C++ queue doesn't have the remove function
// use deque to store the index, maintain the decreasing order in the queue, 
// since the elements in the deque are all within the window, push the top of it into res

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> res;
		if (nums.empty() || k == 0)
			return res;
		deque<int> dq;
		for (int i = 0; i<nums.size(); i++) {
			if (!dq.empty() && dq.front() == i - k)
				dq.pop_front();
			while (!dq.empty() && nums[dq.back()] < nums[i])
				dq.pop_back();
			dq.push_back(i);
			if (i >= k - 1)
				res.push_back(nums[dq.front()]);
		}
		return res;
	}
};