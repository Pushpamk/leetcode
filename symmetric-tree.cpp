/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root -> left, root -> right);
    }

private:
    
    bool helper(TreeNode* node_l, TreeNode* node_r) {
        if (node_l == NULL || node_r == NULL)
            return node_l == node_r;
        return (node_l -> val == node_r -> val && helper(node_l -> right, node_r -> left) && helper(node_l -> left, node_r -> right));
    }
};
