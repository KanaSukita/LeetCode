// Given a binary tree, find the length of the longest consecutive sequence path.
// 
// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
// 
// For example,
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
// Longest consecutive sequence path is 3-4-5, so return 3.
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.



// Idea:
// dfs
// write a helper function with current len and global len and the target of next value

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
    int longestConsecutive(TreeNode* root) {
        int res = 0;
        if(!root)
            return res;
        helper(root, 0, root->val, res);
        return res;
    }
    void helper(TreeNode* root, int cur, int target, int &res){
        if(!root)
            return;
        if(root->val == target)
            cur++;
        else
            cur = 1;
        res = max(cur, res);
        helper(root->left, cur, root->val + 1, res);
        helper(root->right, cur, root->val + 1, res);
    }
};

