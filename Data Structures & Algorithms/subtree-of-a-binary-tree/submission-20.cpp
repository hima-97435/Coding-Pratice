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
    string serialise(TreeNode* root){
        if(root == nullptr) return "$#";
        return "$"+to_string(root->val)+serialise(root->left)+serialise(root->right);
        
    }
    vector<int> zfucntion(string s){
        vector<int> z(s.size());
        int l = 0 , r = 0, n = s.size();
        for( int i=1;i<n;i++){
            if(i<=r) z[i]=min(r-i+1,z[i-l]);
            while(i+z[i]<n && s[z[i]] == s[i+z[i]]) z[i]++;
            if(i+z[i]-1>r){
                l=i;
                r=i+z[i]-1;
            }
        } 
        return z;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string z = serialise(root);
        string x = serialise(subRoot);
        string combined = x+"|"+z;
        vector<int> zvalues = zfucntion(combined);
        int sublen = x.size();
        for(int i=sublen-1;i<combined.size();i++){
            if(zvalues[i] == sublen) return true;
        }
        return false;
    }
};
