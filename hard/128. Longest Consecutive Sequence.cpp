// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

// For example,
// Given[100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is[1, 2, 3, 4].Return its length : 4.

// Your algorithm should run in O(n) complexity.



// Idea:
// Use a hash table to store the length of a sequence start with i and end with j: m[i] = m[j] = len
// scan the array once and if the value has been scan, skip

// Another idea :
// neither i + 1 nor i - 1 has been seen : m[i] = 1;
// both i + 1 and i - 1 have been seen : extend m[i + m[i + 1]] and m[i - m[i - 1]] to each other;
// only i + 1 has been seen : extend m[i + m[i + 1]] and m[i] to each other;
// only i - 1 has been seen : extend m[i - m[i - 1]] and m[i] to each other.

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (num.size() < 2)
			return num.size();
		unordered_map<int, int> m;
		int res = 1;
		for (int n : num) {
			if (m.find(n) != m.end()) continue;
			m[n] = 1;
			if (m.find(n - 1) != m.end()) {
				int len = m[n] + m[n - 1];
				m[n] = len;
				m[n - len + 1] ++;
				res = max(res, len);
			}
			if (m.find(n + 1) != m.end()) {
				int len = m[n + m[n + 1]] + m[n];
				int start = n - m[n] + 1;
				int end = n + m[n + 1];
				m[start] = len;
				m[end] = len;
				res = max(res, len);
			}
		}
		return res;
	}
};