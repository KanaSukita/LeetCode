// We have two special characters. The first character can be represented by one bit 0. 
// The second character can be represented by two bits (10 or 11).

// Now given a string represented by several bits.Return whether the last character must be a one - bit character or not.
// The given string will always end with a zero.



// Idea:
// skip an index and mark the res as false when a zero appears, otherwise set the mark as true

class Solution {
public:
	bool isOneBitCharacter(vector<int>& bits) {
		bool res;
		for (int i = 0; i<bits.size(); i++) {
			if (bits[i]) {
				res = false;
				i++;
			}
			else
				res = true;
		}
		return res;
	}
};