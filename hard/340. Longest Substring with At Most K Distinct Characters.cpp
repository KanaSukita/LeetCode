// Given a string, find the length of the longest substring T that contains at most k distinct characters.

// For example, Given s = ¡°eceba¡± and k = 2,

// T is "ece" which its length is 3.



// Idea:
// template

class Solution {
public:
	int lengthOfLongestSubstringKDistinct(string s, int k) {
		vector<int> m(128, 0);
		int count = 0, begin = 0, end = 0, d = 0;
		while (end < s.size()) {
			if (m[s[end++]]++ == 0)
				count++;
			while (count>k) {
				if (m[s[begin++]]-- == 1)
					count--;
			}
			d = max(d, end - begin);
		}
		return d;
	}
};