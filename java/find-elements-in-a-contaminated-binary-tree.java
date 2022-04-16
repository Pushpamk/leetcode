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
class FindElements {
    private HashSet<Integer> hs;
    
    private void buildTree(TreeNode node, int value) {
        if (node == null)
            return;
        hs.add(value);
        node.val = value;

        buildTree(node.left, node.val * 2 + 1);
        buildTree(node.right, (node.val * 2) + 2);
    }

    public FindElements(TreeNode root) {
        hs = new HashSet<>();
        buildTree(root, 0);
    }
    
    public boolean find(int target) {
        return hs.contains(target);
    }
}

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements obj = new FindElements(root);
 * boolean param_1 = obj.find(target);
 */
