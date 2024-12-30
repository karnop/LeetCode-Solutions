/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_map) {
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(current->left) {
                parent_map[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent_map[current->right] = current;
                q.push(current->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_map;
        markParents(root, parent_map);

        unordered_map<TreeNode*, bool> visited;
        queue <TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while(!q.empty()) {
            int size = q.size();
            if(curr_level++ == k) break;
            for(int i = 0; i<size; i++){
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right] = true;
                } 

                if(parent_map[current] && !visited[parent_map[current]]){
                    q.push(parent_map[current]);
                    visited[parent_map[current]] = true;
                } 
            }
        }

        vector<int> result;
        while(!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            result.push_back(front->val);
        }

        return result;

    }
};