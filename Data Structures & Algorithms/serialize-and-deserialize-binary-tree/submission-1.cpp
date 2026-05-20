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

class Codec {
public:

    // Encodes a tree to a single string.\
    // structure like root#left#right#left->left#
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s ;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr == nullptr){
                s+="#,";

            }
            else {
                s+=to_string(curr->val)+",";
                // if(!curr->left) 
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return nullptr;
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr= q.front();
            q.pop();
            if(getline(ss, str,',')){
                if(str!="#")
                {
                TreeNode* l = new TreeNode(stoi(str));
                curr->left = l;
                q.push(l);
                }
            }
            if(getline(ss, str,',')){
                if(str!="#")
                {
                TreeNode* r = new TreeNode(stoi(str));
                curr->right = r;
                q.push(r);
                }
            }
        }
        return root;
    }
};
