/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    TreeNode ans = null;
    public void search(TreeNode root, TreeNode cloned, TreeNode target)
    {
        if(root == null) return;
        if(root == target) ans = cloned;
        search(root.left, cloned.left, target); 
        search(root.right, cloned.right, target);  
    }
    public final TreeNode getTargetCopy(final TreeNode original, final TreeNode cloned, final TreeNode target) 
    {
        search(original, cloned, target);
        return ans;
    }
}