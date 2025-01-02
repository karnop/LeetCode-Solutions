/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front == nullptr) s.append("#, ");
            else s.append(to_string(front->val) + ", ");

            if(front != nullptr) {
                q.push(front->left);
                q.push(front->right);
            } 
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;

        stringstream ss(data);
        string item;
        getline(ss, item, ',');
        item.erase(remove(item.begin(), item.end(), ' '), item.end());
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();

            // processing left child
            if(getline(ss, item, ',')) {
                // removing the space
                item.erase(remove(item.begin(), item.end(), ' '), item.end());
                if(item != "#") {
                    TreeNode* leftChild = new TreeNode(stoi(item));
                    current->left = leftChild;
                    q.push(leftChild);
                }
            }

            // processing left child
            if(getline(ss, item, ',')) {
                // removing the space
                item.erase(remove(item.begin(), item.end(), ' '), item.end());
                if(item != "#") {
                    TreeNode* rightChild = new TreeNode(stoi(item));
                    current->right = rightChild;
                    q.push(rightChild);
                }
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));