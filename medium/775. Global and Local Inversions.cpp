// We have some permutation A of [0, 1, ..., N - 1], where N is the length of A.

// The number of(global) inversions is the number of i < j with 0 <= i < j < N and A[i] > A[j].

// The number of local inversions is the number of i with 0 <= i < N and A[i] > A[i + 1].

//     Return true if and only if the number of global inversions is equal to the number of local inversions.



// Idea:
// first compute the local inversions
// use an integer temp to represent how many possible smaller integers are left, traverse the elements in front to wipe them out, 
// the loop stops when j = 0 or temp = 0

class Solution {
public:
	bool isIdealPermutation(vector<int>& A) {
		int N = A.size(), g = 0, l = 0;
		g += A[0];
		for (int i = 0; i<N - 1; i++) {
			if (A[i] > A[i + 1])
				l++;
		}
		for (int i = 1; i<N; i++) {
			int temp = A[i], j = i - 1;
			while (temp > 0 && j >= 0) {
				if (A[j] < A[i])
					temp--;
				j--;
			}
			g += temp;
		}
		return g == l;
	}
};