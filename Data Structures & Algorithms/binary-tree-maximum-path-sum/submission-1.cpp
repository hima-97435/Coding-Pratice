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
    int maxPathSum(TreeNode* root) {
        // left tree ka max and then right tree ka max
        int minvalue=INT_MIN;
        solve(root, minvalue);
        return minvalue;
    }
    int solve(TreeNode* root , int& value ){
        if(!root) return 0;
        // value=max(root->val , value);
        int lmax = max(0,solve(root->left, value));
        int rmax = max(0,solve(root->right, value));
        int curr = root->val+lmax+rmax;
        value=max(value, curr);
        return root->val+max(lmax,rmax);
    }
};
