// Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once.
// You must make sure your result is the smallest in lexicographical order among all possible results.

// Example:
// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"



// Idea:
// use a map to represent the times of the character and a flag to represent if the character is in the result.
// traverse the string from left to right, compare the current character with the back of the result, 
// if the ramaining times of the back is greater than 0 and the current character is smaller than the back, 
// pop the back and add the currenent character

class Solution {
public:
	string removeDuplicateLetters(string s) {
		if (s.length() < 2)
			return s;
		vector<int> m(26, 0);
		vector<bool> flags(26, false);
		for (auto c : s)
			m[c - 'a']++;
		string res = " ";
		for (auto c : s) {
			m[c - 'a']--;
			if (flags[c - 'a'])
				continue;
			while (c < res.back() && m[res.back() - 'a']) {
				flags[res.back() - 'a'] = false;
				res.pop_back();
			}
			res += c;
			flags[c - 'a'] = true;
		}
		return res.substr(1);
	}
};