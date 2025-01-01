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
    int leftHeight(TreeNode* root) {
        int ht = 0;
        while(root!= nullptr){
            ht++;
            root = root->left;
        }
        return ht;
    }

    int rightHeight(TreeNode* root) {
        int ht = 0;
        while(root!= nullptr){
            ht++;
            root = root->right;
        }
        return ht;
    }

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if(lh == rh) return (1<<lh)-1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};