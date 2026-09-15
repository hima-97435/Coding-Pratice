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

    // Encodes a tree to a single string.
    void helpserialize(TreeNode* node, string&ans){
        if(!node) {ans+="#,"; return;}
        
        ans +=to_string(node->val);
        ans+=',';
        helpserialize(node->left,ans);
        helpserialize(node->right,ans);
        
    }
    string serialize(TreeNode* root) {
        string ans;
        helpserialize(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* helpderserialize(stringstream &ss){
        string token;
        getline(ss,token,',');
        if(token == "#" ) return nullptr;
        TreeNode* cur = new TreeNode(stoi(token));
        cur->left=helpderserialize(ss);
        cur->right=helpderserialize(ss);
        return cur;
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return helpderserialize(ss);
    }
};
