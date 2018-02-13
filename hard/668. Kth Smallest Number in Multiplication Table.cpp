// Nearly every one have used the Multiplication Table.But could you find out the k - th smallest number quickly from the multiplication table ?

// Given the height m and the length n of a m * n Multiplication Table, and a positive integer k, you need to return the k - th smallest number in this table.

// Example 1 :
//		Input : m = 3, n = 3, k = 5
//		Output :
// Explanation :
//	The Multiplication Table :
//				1	2	3
//				2	4	6
//				3	6	9

// The 5 - th smallest number is 3 (1, 2, 2, 3, 3).



// Idea:
// using the method of binary search
// for a certain number, there are min(n, num / i) numbers in a ros that is smaller than it

class Solution {
public:
	int findKthNumber(int m, int n, int k) {
		int left = 1, right = m * n;
		while (left < right) {
			int mid = left + (right - left) / 2, cnt = 0;
			for (int i = 1; i <= m; ++i) {
				cnt += (mid / i <= n) ? (mid / i) : n;
			}
			if (cnt < k) left = mid + 1;
			else right = mid;
		}
		return left;
	}
};