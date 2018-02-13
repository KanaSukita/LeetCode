// Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.

// Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree. Also, a node is called a leaf if it has no children.

// In the following examples, the input tree is represented in flattened form row by row. The actual root tree given will be a TreeNode object.

// Input:
// root = [1,2,3,4,null,null,null,5,null,6], k = 2
// Diagram of binary tree:
//             1
//            / \
//           2   3
//          /
//         4
//        /
//       5
//      /
//     6

// Output: 3
// Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.



// Idea:
// use a hash map to store the distance from k to its parent node,
// traverse all the nodes, if m[node->val] exist , find the leaf, try to update res

// hint: it's hard to compute the distance from k to all the nodes at once, so it's reasonable to just compute the distance to its parent(also itself), and then use another help function to compute the diatsnce if the node is a leaf

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
    int findClosestLeaf(TreeNode* root, int k) {
        int res = -1, mn = INT_MAX;
        unordered_map<int, int> m;
        m[k] = 0;
        find(root, k, m);
        helper(root, -1, m, mn, res);
        return res;
    }
    int find(TreeNode* node, int k, unordered_map<int, int>& m) {
        if (!node) return -1;
        if (node->val == k) return 1;
        int r = find(node->left, k, m);
        if (r != -1) {
            m[node->val] = r; 
            return r + 1;
        }
        r = find(node->right, k, m);
        if (r != -1) {
            m[node->val] = r;
            return r + 1;
        }
        return -1;
    }
    void helper(TreeNode* node, int cur, unordered_map<int, int>& m, int& mn, int& res) {
        if (!node) 
            return;
        if(m.find(node->val) != m.end())
            cur = m[node->val];
        if (!node->left && !node->right) {
            if (mn > cur) {
                mn = cur; 
                res = node->val;
            }
        }
        helper(node->left, cur + 1, m, mn, res);
        helper(node->right, cur + 1, m, mn, res);
    }
};

