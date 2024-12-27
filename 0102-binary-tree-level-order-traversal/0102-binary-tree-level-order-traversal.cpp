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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> temp;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* elem = q.front();
                q.pop();
                temp.push_back(elem->val);

                if(elem->left) q.push(elem->left);
                if(elem->right) q.push(elem->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};