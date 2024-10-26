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
    int height(TreeNode* node) {
        if(node == nullptr) return 0;
        return 1 +(max(height(node->left), height(node->right)));
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        int abssum = abs(height(root->left) - height(root->right));
        cout << abssum;
        if(abssum > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};