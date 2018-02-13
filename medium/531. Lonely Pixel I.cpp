// Given a picture consisting of black and white pixels, find the number of black lonely pixels.

// The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively.

// A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.




// Idea:
// bruto force, use two vector to represent the number of B in row and col, res is the sum of (i, j) such that row[i]==1 and col[j]==1

class Solution {
public:
	int findLonelyPixel(vector<vector<char>>& picture) {
		int n = picture.size();
		if (!n)
			return 0;
		int m = picture[0].size(), res = 0;
		vector<int> row(n, 0), col(m, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (picture[i][j] == 'B') {
					row[i]++;
					col[j]++;
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			if (row[i] != 1)
				continue;
			for (int j = 0; j < m; ++j) {
				if (picture[i][j] == 'B') {
					if (col[j] == 1) {
						res++;
					}
					break;
				}
			}
		}
		return res;
	}
};