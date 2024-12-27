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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       queue<TreeNode*> q;
       vector<vector<int>> ans;

       if(root != nullptr) q.push(root);
       bool flag = true;
       while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            for(int i=0; i<size; i++){
                TreeNode* top = q.front();
                q.pop();
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                temp.push_back(top->val);
            }
            if(!flag) reverse(temp.begin(), temp.end());
            flag = !flag;
            ans.push_back(temp);
       }
       return ans;
    }
};