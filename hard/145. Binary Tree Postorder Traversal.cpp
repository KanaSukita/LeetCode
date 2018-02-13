//	Given a binary tree, return the postorder traversal of its nodes' values.

//	For example :
//	Given binary tree[1, null, 2, 3],

//			1
//		     \
//			  2
//			 /
//          3

// Idea:
// recursion and postorder

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
	vector<int> postorderTraversal(TreeNode* root) {
		posTra(root, res);
		return res;
	}
	void posTra(TreeNode* root, vector<int> &res) {
		if (!root)
			return;
		posTra(root->left, res);
		posTra(root->right, res);
		res.push_back(root->val);
		return;
	}
private:
	vector<int> res;
};