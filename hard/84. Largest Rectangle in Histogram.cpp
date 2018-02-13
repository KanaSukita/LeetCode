// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

// Above is a histogram where width of each bar is 1, given height = [2, 1, 5, 6, 2, 3].

// The largest rectangle is shown in the shaded area, which has area = 10 unit.

// For example,
// Given heights = [2, 1, 5, 6, 2, 3],
// return 10.



// Idea:
// when a smaller height appears, pop the heights in the stack until the smaller heights is greater than the top, 
// in each pop operation, check the possibilities in front, where each contains two parts, left and right

class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int res = 0, left = 0, right = 0;
		stack<int> s;
		heights.push_back(0);
		for (int i = 0; i< heights.size(); i++) {
			while (!s.empty() && heights[s.top()] > heights[i]) {
				int temp = s.top();
				s.pop();
				left = (s.empty() ? temp + 1 : temp - s.top()) * heights[temp];
				right = (i - temp - 1) * heights[temp];
				if (left + right > res)
					res = left + right;
			}
			s.push(i);
		}
		return res;
	}
};
