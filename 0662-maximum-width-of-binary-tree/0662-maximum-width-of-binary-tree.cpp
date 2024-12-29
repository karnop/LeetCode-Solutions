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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long int>> q;
        long long width = 0;

        if(!root) return 0;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            long long first = 0, second = 0;
            long long minpos = q.front().second; 
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                long long pos = q.front().second; 
                pos = pos - minpos;    
                q.pop();
                if(i == 0) {
                    first = pos;    
                }
                else if(i == size-1) second = pos;
                if(node->left) q.push({node->left, (2*(pos))+1});
                if(node->right) q.push({node->right, (2*(pos))+2});
            }
            width = max(width, second-first+1);
        }
        return width;       
    }
};