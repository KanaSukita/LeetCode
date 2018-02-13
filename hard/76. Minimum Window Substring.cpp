// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".

// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.




// Idea:
// using the template
// some explanations : use a map to stores the appearence of the wanted substring, when all the m[c] <= 0 means there are no 
// remains the the string, and the current head to end is a window for the substring.
// Next, we can increase the begin and find a new window.
// Only update head and d when(end - begin) < d

class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> map(128, 0);
		for (auto c : t)
			map[c]++;
		int remains = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
		while (end<s.size()) {
			if (map[s[end++]]-- > 0)
				remains--;
			while (remains == 0) {
				if (end - begin<d)
					d = end - (head = begin);
				if (map[s[begin++]]++ == 0)
					remains++;
			}
		}
		return d == INT_MAX ? "" : s.substr(head, d);
	}
};