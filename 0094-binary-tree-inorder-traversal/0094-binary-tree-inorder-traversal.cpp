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
    vector<int> inorderTraversal(TreeNode* root) {
        // morris
        vector<int> inorder;
        TreeNode* curr = root;

        while(curr != nullptr) {
            if(curr->left == nullptr) {
                inorder.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                // if thread exists
                if(prev->right == curr) {
                    prev->right = nullptr;
                    inorder.push_back(curr->val);
                    curr = curr->right;
                }

                else {
                    prev->right = curr;
                    curr = curr->left;
                }
            }
        }
        return inorder;
    }

};