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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        preOrder(root, ans, "");
        return ans;
    }
    
    void preOrder(TreeNode* root, vector<string>& ans, string s) {
        if (root -> left == NULL && root -> right == NULL) {
            ans.push_back(s += to_string(root -> val));
        }
        s +=  to_string(root->val) + "->";
        
        if (root -> left != NULL)
            preOrder(root -> left, ans, s);
        
        if (root -> right != NULL)
            preOrder(root -> right, ans, s);
    }
};
