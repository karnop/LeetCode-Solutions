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
    public boolean check(TreeNode left, TreeNode right)
    {
        int leftval = -999;
        int rightval = -999;
        if(left!=null)  leftval = left.val;
        if(right!=null) rightval = right.val;
        System.out.println("Checking " + leftval + " and " + rightval);
        if(left == null && right == null)   return true;
        else if(left == null || right == null)  return false;
        if(left.val != right.val)   return false;
        return check(left.left, right.right) && check(left.right, right.left);
    }
    public boolean isSymmetric(TreeNode root) 
    {
        return check(root, root);
    }
}