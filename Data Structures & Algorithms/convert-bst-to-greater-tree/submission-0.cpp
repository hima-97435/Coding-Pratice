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
    int cursum =0;
public:
    TreeNode* convertBST(TreeNode* root) {
        dfs(root);
        return root;
    }
    void dfs(TreeNode* node){
        if(!node) return;
        dfs(node->right);
        int tmp = node->val;
        node->val+=cursum;
        cursum+=tmp;
        dfs(node->left);
    }
};