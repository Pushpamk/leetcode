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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<Integer>();
        Queue<TreeNode> queue = new LinkedList();
        if (root == null)
            return ans;
        queue.offer(root);
        while (!queue.isEmpty()) {
            int size = queue.size();
            while (size-- > 0) {
                TreeNode cur = queue.poll();
                if (size == 0)
                    ans.add(cur.val);
                if (cur.left != null)
                    queue.offer(cur.left);
                if (cur.right != null) 
                    queue.offer(cur.right);
            }
        }
        return ans;
    }
}
