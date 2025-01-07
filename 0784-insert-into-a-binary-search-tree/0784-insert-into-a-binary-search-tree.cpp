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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr) return new TreeNode(val);
        TreeNode* reqleaf = root;
        
        while(true) {
            if(reqleaf->val < val) {
                if(reqleaf->right == nullptr) {
                    reqleaf->right = new TreeNode(val);
                    break;
                }
                else reqleaf = reqleaf->right;
            }
            
            if(reqleaf->val > val) {
                if(reqleaf->left == nullptr) {
                    reqleaf->left = new TreeNode(val);
                    break;
                }
                else reqleaf = reqleaf->left;
            }
        }

        return root;
    }
};