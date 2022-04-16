/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int goodNodes(TreeNode root) {
        return helper(root, -100001);
    }
    public int helper(TreeNode root, int max) {
        return root == null ? 0 : helper(root.left, Math.max(max, root.val)) + helper(root.right, Math.max(root.val, max)) + (root.val >= max ? 1 : 0);
    }
}
