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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        unordered_map<int, vector<int>> cols;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        int mincol =0, maxcol =0;
        while(!q.empty()){
            auto [node, col]= q.front();
            q.pop();
            cols[col].push_back(node->val);
            mincol=min(mincol , col);
            maxcol=max(maxcol , col);
            if(node->left) q.push({node->left, col-1});
            if(node->right) q.push({node->right, col+1});
            
        }
        vector<vector<int>> res;
        for(int c = mincol;c<=maxcol;c++){
            res.push_back(cols[c]);
        }
        return res;
    }
};