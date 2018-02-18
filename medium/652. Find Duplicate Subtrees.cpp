// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//
// Two trees are duplicate if they have the same structure with same node values.
//
// Example 1: 
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
// The following are two duplicate subtrees:
//       2
//      /
//     4
// and
//     4
// Therefore, you need to return above trees' root in the form of a list.



// Idea:
// use an unordered map and use inorder/postorder to represent the sub tree
// attention: use "(" and ")" to avoid two different trees with the same order, and also use a vector the the map, if the size is greater than 2 it's duplicate

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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        if(!root)
            return res;
        unordered_map<string,vector<TreeNode*>> m;
        helper(root->left, m);
        helper(root->right, m);
        for(auto it=m.begin();it!=m.end();it++){
            if(it->second.size()>1)  
                res.push_back(it->second[0]);  
        }
        return res;
    }
    string helper(TreeNode* root, unordered_map<string,vector<TreeNode*>> &m){
        string s = "";
        if(!root)
            return s;
        s = "(" + helper(root->left, m) + to_string(root->val) + helper(root->right, m) + ")";
        m[s].push_back(root);
        return s;
    }
};