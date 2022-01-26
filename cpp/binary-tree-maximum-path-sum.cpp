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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
private:
    int solve(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int l, r;
        l = solve(root -> left, ans);
        r = solve(root -> right, ans);
        int tmp = max(max(l, r) + root -> val, root -> val);
        int res = l + r + root -> val;
        ans = max(max(res, tmp), ans);
        return tmp;
    }
    
};
