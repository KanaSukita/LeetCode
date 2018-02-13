// Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).



// Idea:
// using the method of recursion
// use a cur to represent the current level

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (!root)
			return res;
		helper(root, 1, res);
		return res;
	}
	void helper(TreeNode* root, int cur, vector<vector<int>> &res) {
		if (cur > res.size()) {
			vector<int> temp = { root->val };
			res.push_back(temp);
		}
		else
			res[cur - 1].push_back(root->val);
		if (root->left)
			helper(root->left, cur + 1, res);
		if (root->right)
			helper(root->right, cur + 1, res);
	}
};