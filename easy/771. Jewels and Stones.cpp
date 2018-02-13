// You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  
// Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

// The letters in J are guaranteed distinct, and all characters in J and S are letters.Letters are case sensitive, 
// so "a" is considered a different type of stone from "A".



// Idea:
// use a map to store the number of the each type of stones
// traverse the jewels srting to find the total number

class Solution {
public:
	int numJewelsInStones(string J, string S) {
		unordered_map<char, int> m;
		for (auto c : S)
			m[c]++;
		int res = 0;
		for (auto c : J)
			res += m[c];
		return res;
	}
};