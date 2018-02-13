// Given a Binary Search Tree (BST) with the root node root, return the minimum difference between the values of any two different nodes in the tree.

// Example :

// Input: root = [4,2,6,1,3,null,null]
// Output: 1
// Explanation:
// Note that root is a TreeNode object, not an array.

// The given tree [4,2,6,1,3,null,null] is represented by the following diagram:

//          4
//        /   \
//      2      6
//     / \    
//    1   3  

// while the minimum difference in this tree is 1, it occurs between node 1 and node 2, also between node 3 and node 2.



// Idea:
// Implement an in-order traversal and find the minimum distance

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
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX, cur = INT_MAX;
        helper(root, res, cur);
        return res;
    }
    void helper(TreeNode* node, int &res, int &cur){
        if(!node)
            return;
        helper(node->left, res, cur);
        if(cur != INT_MAX && node->val - cur < res)
            res = node->val - cur;
        cur = node->val;
        helper(node->right, res, cur);
    }
};