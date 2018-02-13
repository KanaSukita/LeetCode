// Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, 
// find the smallest element in the list that is larger than the given target.

//Letters also wrap around.For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.



// Idea:
// simple binary search

class Solution {
public:
	char nextGreatestLetter(vector<char>& letters, char target) {
		int l = 0, r = letters.size() - 1;
		char last = letters[r];
		if (target >= last)
			return letters[l];
		while (l<r) {
			int m = (l + r) / 2;
			if (letters[m] <= target)
				l = m + 1;
			else
				r = m;
		}
		return letters[l];
	}
};