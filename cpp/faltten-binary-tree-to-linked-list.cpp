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
    void flatten(TreeNode* root) {
        preOrder(root, NULL);
    }
    
    TreeNode* preOrder(TreeNode* root, TreeNode* next) {
        if (!root)
            return next;
        next = preOrder(root -> right, next);
        next = preOrder(root -> left, next);
        root -> right = next;
        root -> left = NULL;
        return root;
    }
};
