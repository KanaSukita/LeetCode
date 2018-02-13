// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.

// Example:
//	Given matrix = [
//					[1, 0, 1],
//					[0, -2, 3]
//							  ]
//	k = 2
//	The answer is 2. Because the sum of rectangle[[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k(k = 2).

//	Note:
//	The rectangle inside the matrix must have an area > 0.
//	What if the number of rows is much larger than the number of columns ?



//	Idea:
// first thougt: bruto force, sum[i][j] as the sum from (0, 0) to (i, j), traverse all posibilities

// solution from the internet :
// You can do this in O(nlog(n))

// First thing to note is that sum of subarray(i, j] is just the sum of the first j elements less the sum of the first i elements.
// Store these cumulative sums in the array cum.Then the problem reduces to finding  i, j such that i<j and cum[j]−cum[i] is as close to 
// k but lower than it.

// To solve this, scan from left to right.Put the cum[i] values that you have encountered till now into a set.When you are processing cum[j] 
// what you need to retrieve from the set is the smallest number in the set such which is not smaller than cum[j]−k.This lookup can be done 
// in O(log(n)) using lower_bound.Hence the overall complexity is O(nlog⁡(n)).

// Here is a c++ function that does the job, assuming that K>0 and that the empty interval with sum zero is a valid answer.The code can be 
// tweaked easily to take care of more general cases and to return the interval itself.

class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
		int row = matrix.size();
		if (row == 0)
			return 0;
		int col = matrix[0].size();
		int ret = INT_MIN;
		for (int l = 0; l < col; l++) {
			vector<int> sums(row, 0);
			for (int r = l; r < col; r++) {
				for (int i = 0; i < row; i++)
					sums[i] += matrix[i][r];
				set<int> sumSet;
				sumSet.insert(0);
				int curSum = 0;
				int curMax = INT_MIN;
				for (auto sum : sums) {
					curSum += sum;
					auto it = sumSet.lower_bound(curSum - k);
					if (it != sumSet.end())
						curMax = max(curMax, curSum - *it);
					sumSet.insert(curSum);
				}
				ret = max(ret, curMax);
			}
		}
		return ret;
	}
};