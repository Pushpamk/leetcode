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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return buildTree(nums, 0, nums.size() - 1);
    }
    TreeNode* buildTree(vector<int>& nums, int low, int high) {
        if (low > high)
            return NULL;
        int maxNum = INT_MIN, cur = -1;
        for (int i = low; i <= high; i++) {
            if (maxNum < nums[i]) {
                maxNum = nums[i];
                cur = i;
            }
        }
        TreeNode* root = new TreeNode(maxNum);
        root -> left = buildTree(nums, low, cur - 1);
        root -> right = buildTree(nums, cur + 1, high);
        return root;
    }
};
