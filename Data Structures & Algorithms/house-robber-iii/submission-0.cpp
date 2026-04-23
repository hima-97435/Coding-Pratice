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
    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first,res.second);
    }
    private:
    pair<int , int> dfs(TreeNode* root){
        if(!root) return {0,0};
        auto lpair = dfs(root->left);
        auto rpair = dfs(root->right);

        int withroot =root->val + lpair.second+rpair.second;
        int withoutroot =max(lpair.second,lpair.first)+max(rpair.second,rpair.first);
        return {withroot,withoutroot};
                
    }
};