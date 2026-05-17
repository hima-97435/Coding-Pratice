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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
    bool dfs(TreeNode* node, long long minval , long long maxval){
        if(!node) return true;
        if(node->val<=minval || node->val>=maxval ) {
            return false;
        }
        return dfs(node->right , node->val,maxval) && dfs(node->left, minval, node->val);
    }
};
