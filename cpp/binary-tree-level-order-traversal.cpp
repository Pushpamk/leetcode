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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == NULL)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode*> stk, q;
        stk.push(root);
        while (!stk.empty()) {
            vector<int> tmp;

            while(!stk.empty()) {
                TreeNode* cur = stk.front();
            
                tmp.push_back(cur -> val);
                stk.pop();
                if (cur -> left != NULL) {
                    q.push(cur -> left);
                }
                if (cur -> right != NULL) {
                    q.push(cur -> right);
                }
            }
            ans.push_back(tmp);
            swap(stk, q);
        }
        return ans;
    }
};
