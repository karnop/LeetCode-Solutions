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
    public void path(TreeNode root, String path, ArrayList<String> list)
    {
        if(root == null) 
        {
            return;
        }
        if(root.left == null && root.right == null)
        {
            path = path.concat(Integer.toString(root.val));
            list.add(path);
            return;
        }
        path = path.concat(root.val+"->");
        path(root.left, path, list);
        path(root.right, path, list);
    }
    public List<String> binaryTreePaths(TreeNode root) 
    {
        ArrayList<String> ans = new ArrayList<>();
        path(root, "", ans);
        return ans;
    }
}