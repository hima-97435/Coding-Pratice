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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        targetSum-=root->val;
        return (hasPathSum(root->left,targetSum) ||
                hasPathSum(root->right,targetSum) ||
                (targetSum ==0  && !root->left && !root->right)
                );
    }
    // okayy , we want to do traversal
    // brute force way , go with post or pre order traversal and 
    // maintain the answer value or simply de=crement targetsum 
    // and if it reaches 0 that is our answer and then returen true;
    
};