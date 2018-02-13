// Given a binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent - child connections.The path must contain at least one node and does not need to go through the root.

// For example :
// Given the below binary tree,

//   1
//  / \
// 2   3
// Return 6.



// Idea:
// use the method of dfs
// create a help function which contain the reference of res and return the maximum of the sum of the values below this node

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
	int maxPathSum(TreeNode* root) {
		if (!root)
			return 0;
		int res = INT_MIN;
		int temp = maxValue(root, res);
		return res;
	}
	int maxValue(TreeNode* node, int &res) {
		if (!node)
			return 0;
		int left = max(maxValue(node->left, res), 0);
		int right = max(maxValue(node->right, res), 0);
		res = max(res, left + right + node->val);
		return max(left, right) + node->val;
	}
};