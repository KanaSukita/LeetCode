//	Given a string, find the length of the longest substring T that contains at most 2 distinct characters.

//	For example, Given s = ¡°eceba¡±,

//	T is "ece" which its length is 3.



// Idea:
// Using the template
// count as types of characters
// moving window and update d when a new maximum appears

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		vector<int> m(128, 0);
		int count = 0, begin = 0, end = 0, d = 0;
		while (end < s.size()) {
			if (m[s[end++]]++ == 0)
				count++;
			while (count>2) {
				if (m[s[begin++]]-- == 1)
					count--;
			}
			d = max(d, end - begin);
		}
		return d;
	}
};

