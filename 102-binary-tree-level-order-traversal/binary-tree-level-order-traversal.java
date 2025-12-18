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
    private void levelOrdRec(TreeNode root, int level, List<List<Integer>> res) {
        if (root == null) {
            return;
        }

        // If the size of res is equal to the current level, it means
        // we are visiting this level for the first time.
        if (res.size() <= level) {
            res.add(new ArrayList<>());
        }

        // Add current node's value to the list corresponding to its level
        res.get(level).add(root.val);

        // Recurse for left and right children, incrementing the level
        levelOrdRec(root.left, level + 1, res);
        levelOrdRec(root.right, level + 1, res);
    }

    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList<>();
        levelOrdRec(root, 0, res);
        return res;
    }
}
