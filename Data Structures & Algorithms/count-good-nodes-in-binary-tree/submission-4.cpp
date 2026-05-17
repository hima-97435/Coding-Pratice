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
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
    int dfs(TreeNode* root, int maxsofar){
        if(root == nullptr) return 0;
        int good =0;
        if(root->val>=maxsofar) {
            good=1;
            maxsofar=root->val;
        }
        int lsubtree= dfs(root->left,maxsofar);
        int rsubtree= dfs(root->right,maxsofar);
        return good+lsubtree+rsubtree;

    }
};
