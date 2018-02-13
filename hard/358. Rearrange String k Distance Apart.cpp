// Given a non-empty string s and an integer k, rearrange the string such that the same characters are at least distance k from each other.

// All input strings are given in lowercase letters.If it is not possible to rearrange the string, return an empty string "".

// Example 1:
// s = "aabbcc", k = 3

// Result : "abcabc"

//		The same letters are at least distance 3 from each other.
//		Example 2 :
//		s = "aaabc", k = 3

//		Answer : ""

//		It is not possible to rearrange the string.
//		Example 3 :
//		s = "aaadbbcc", k = 2

//		Answer : "abacabcd"

//		Another possible answer is : "abcabcda"

//		The same letters are at least distance 2 from each other.



// Idea:
// use the method of greedy, and use a hash table to store the number of characters, and use a priority queue to represent the 
// remaining available times
// take min(k, n) elements in priority queue to fit the result

class Solution {
public:
	string rearrangeString(string s, int k) {
		if (k == 0)
			return s;
		int n = s.length();
		string res;
		map<char, int> m;
		for (int i = 0; i<n; i++)
			m[s[i]] ++;
		priority_queue<pair<int, char>> q;
		for (auto val : m)
			q.push(make_pair(val.second, val.first));
		while (!q.empty()) {
			vector<pair<int, char>> v;
			int count = min(k, n);
			for (int i = 0; i<count; i++, n--) {
				if (q.empty())
					return "";
				auto val = q.top();
				q.pop();
				res += val.second;
				if (--val.first > 0)
					v.push_back(val);
			}
			for (auto val : v)
				q.push(val);
		}
		return res;
	}
};