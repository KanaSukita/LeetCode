// Given a positive integer, check whether it has alternating bits : namely, if two adjacent bits will always have different values.



// Idea:
// n >>= 1 and temp = n & 1
// flip the bit by 1 - temp, if eventually n is 0, return true

class Solution {
public:
	bool hasAlternatingBits(int n) {
		int temp = n & 1;
		while ((n & 1) == temp) {
			temp = 1 - temp;
			n >>= 1;
		}
		return n == 0;
	}
};