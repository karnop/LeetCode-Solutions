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
    int max = Integer.MIN_VALUE;
    public int maxNodeSum(TreeNode root)
    {
        if(root == null)    return 0;

        int l = maxNodeSum(root.left);
        int r = maxNodeSum(root.right);
        max = Math.max(max, (root.val+ Math.max(0,  l) + Math.max(0,  r)));
        
        int ret = Math.max(l, r);
        ret = Math.max(0, ret);
        return ret+root.val;
    }
    public int maxPathSum(TreeNode root) 
    {
        maxNodeSum(root);
        return max;
    }
}