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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // map for levels // multiset used instead of vector to sort the values
        map<int, map<int, multiset<int>>> levels;

        // queue individual node with row and cols
        queue <pair<TreeNode* , pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto [node, coords] = q.front();
            int row = coords.first, col = coords.second;
            q.pop();

            if(node == nullptr) continue;
            levels[col][row].insert(node->val);
            q.push({node->left,{ row+1, col-1}});
            q.push({node->right,{ row+1, col+1}});
        }

        vector<vector<int>> ans;
        for(auto level: levels) {
            vector<int> col;
            for(auto rows : level.second) {
                col.insert(col.end(), rows.second.begin(), rows.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};