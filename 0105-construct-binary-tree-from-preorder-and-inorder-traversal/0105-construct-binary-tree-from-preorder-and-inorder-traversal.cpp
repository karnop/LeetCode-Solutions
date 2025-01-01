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
    TreeNode* build(vector<int> &preorder, int preorderStart, int preorderEnd,
     vector<int> &inorder, int inorderStart, int inorderEnd, map<int, int> &map){
        if(preorderStart > preorderEnd || inorderStart > inorderEnd) return nullptr;
        TreeNode* root = new TreeNode(preorder[preorderStart]);

        int inorderRoot = map[root->val];
        int numsLeft = inorderRoot-inorderStart;

        root->left = build(preorder, preorderStart+1, preorderStart+numsLeft, inorder, inorderStart, inorderRoot-1, map);
        root->right = build(preorder, preorderStart+numsLeft+1, preorderEnd, inorder, inorderRoot + 1, inorderEnd, map);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> hm;
        for(int i=0; i<inorder.size(); i++)
            hm[inorder[i]] = i;

        TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size()-1, hm);
        return root;
    }
};