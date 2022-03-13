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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q, q1;
        vector<int> ans;
        if (!root)
            return {};
        q.push(root);
        while (!q.empty()) {
            int cur_max = INT_MIN;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                cur_max = max(cur_max, cur -> val);
                if (cur -> left)
                    q1.push(cur -> left);
                if (cur -> right)
                    q1.push(cur -> right);
            }
            ans.push_back(cur_max);
            swap(q, q1);
        }
        return ans;
    }
};
