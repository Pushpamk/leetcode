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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = -1;
        solve(root, ans);
        return ans;
    }
    
private:
    int solve(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int l, r, temp;
        l = solve(root -> left, ans);
        r = solve(root -> right, ans);
        temp = max(l, r) + 1;
        ans = max(ans, l + r); // not added 1 because we have to return edges, edges = n - 1
        return temp;
    }
};
