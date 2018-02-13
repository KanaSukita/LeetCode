//	An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., 
//	there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, 
//	return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.

//	For example, given the following image :

//	[
//		"0010",
//		"0110",
//		"0100"
//				]
//	and x = 0, y = 2,
//	Return 6.



// Idea:
// Use binary search to find the 4 boundaries
// for the binary search function, add a variable opt to represent if we are trying to find 1 or 0

class Solution {
public:
	int minArea(vector<vector<char>>& image, int x, int y) {
		int n = image.size(), m = image[0].size();
		int top = searchRows(image, 0, x, 0, m, true);
		int bottom = searchRows(image, x + 1, n, 0, m, false);
		int left = searchCols(image, 0, y, top, bottom, true);
		int right = searchCols(image, y + 1, m, top, bottom, false);
		return (right - left) * (bottom - top);
	}
	int searchRows(vector<vector<char>> &image, int i, int j, int low, int high, bool opt) {
		while (i < j) {
			int k = low, mid = (i + j) / 2;
			while (k < high && image[mid][k] == '0')
				k++;
			if (k < high == opt)
				j = mid;
			else
				i = mid + 1;
		}
		return i;
	}
	int searchCols(vector<vector<char>> &image, int i, int j, int low, int high, bool opt) {
		while (i < j) {
			int k = low, mid = (i + j) / 2;
			while (k < high && image[k][mid] == '0')
				k++;
			if (k < high == opt)
				j = mid;
			else
				i = mid + 1;
		}
		return i;
	}
};