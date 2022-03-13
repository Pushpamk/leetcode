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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool toggle = true;
        vector<vector<int>> ans;
        if (!root)
            return {};
        queue<TreeNode*> q, q1;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            while (!q.empty()) {
                TreeNode* cur = q.front();
                q.pop();
                tmp.push_back(cur -> val);
                if (cur -> left)
                    q1.push(cur -> left);
                if (cur -> right)
                    q1.push(cur -> right);
            }
            if (toggle) {
                ans.push_back(tmp);
                toggle = !toggle;
            }
            else {
                reverse(tmp.begin(), tmp.end());
                ans.push_back(tmp);
                toggle = !toggle;
            }
            swap(q, q1);
        }
        return ans;
    }
};
