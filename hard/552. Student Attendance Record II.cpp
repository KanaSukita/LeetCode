// Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. 
// The answer may be very large, return it after mod 109 + 7.

// A student attendance record is a string that only contains the following three characters :

// 'A' : Absent.
// 'L' : Late.
// 'P' : Present.
// A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

// Example 1 :
//		Input : n = 2
//		Output : 8
//		Explanation :
//		There are 8 records with length 2 will be regarded as rewardable :
//			"PP", "AP", "PA", "LP", "PL", "AL", "LA", "LL"
//		Only "AA" won't be regarded as rewardable owing to more than one absent times. 
//		Note : The value of n won't exceed 100,000.



// Idea:
// 思路为：分别用三个dp记录以P A L结尾的个数 寻找dp从n-1到n的关系
// P和L的关系容易得出
// A的关系为A[n] = A[n - 1] + A[n - 2] + A[n - 3] （通过写出A[n]、P[n - 1] | 非A、和L[n - 1] | 非A）的表达式。

class Solution {
public:
	int checkRecord(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 3;
		if (n == 2)
			return 8;
		int m = 1000000007;
		int P[100000];
		int A[100000];
		int L[100000];

		P[0] = 1;
		P[1] = 3;
		L[0] = 1;
		L[1] = 3;
		A[0] = 1;
		A[1] = 2;
		A[2] = 4;

		for (int i = 2; i<n; i++) {
			P[i] = ((P[i - 1] + A[i - 1]) % m + L[i - 1]) % m;
			L[i] = ((P[i - 1] + A[i - 1]) % m + (P[i - 2] + A[i - 2]) % m) % m;
			if (i > 2)
				A[i] = ((A[i - 1] + A[i - 2]) % m + A[i - 3]) % m;
		}
		return ((A[n - 1] + P[n - 1]) % m + L[n - 1]) % m;
	}
};