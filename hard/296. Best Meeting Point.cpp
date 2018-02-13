//	A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, 
//  where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = 
// |p2.x - p1.x| + |p2.y - p1.y|.

//	For example, given three people living at(0, 0), (0, 4), and (2, 2) :

//		1 - 0 - 0 - 0 - 1
//		|   |   |   |   |
//		0 - 0 - 0 - 0 - 0
//		|   |   |   |   |
//		0 - 0 - 1 - 0 - 0
//	The point(0, 2) is an ideal meeting point, as the total travel distance of 2 + 2 + 2 = 6 is minimal.So return 6.



// Idea:
// calculate the median of x and y
// that's the best spot

// hint: use n_element(a.begin(), a + med, a.end())

class Solution {
public:
	int minTotalDistance(vector<vector<int>>& grid) {
		int n = grid.size();
		if (!n)
			return 0;
		int m = grid[0].size(), res = 0;
		vector<int> row, col;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (grid[i][j] == 1) {
					row.push_back(i);
					col.push_back(j);
				}
			}
		}
		nth_element(row.begin(), row.begin() + row.size() / 2, row.end());
		int x_med = row[row.size() / 2];
		nth_element(col.begin(), col.begin() + col.size() / 2, col.end());
		int y_med = col[col.size() / 2];
		for (int r : row)
			res += abs(r - x_med);
		for (int c : col)
			res += abs(c - y_med);
		return res;
	}
};
