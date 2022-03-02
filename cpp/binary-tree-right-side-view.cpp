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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightView(root, ans, 0);
        return ans;
    }
    
private:
    void rightView(TreeNode* cur, vector<int>& ans, int curDepth) {
        if (!cur)
            return;
        if (ans.size() == curDepth)
            ans.push_back(cur -> val);
        rightView(cur -> right, ans, curDepth + 1);
        rightView(cur -> left, ans, curDepth + 1);
    }
};
