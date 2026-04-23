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
        int r = root->val;
        dfs(root, r);
        return r;
    }
private:
int dfs(TreeNode* root, int& res){
    if(!root) return 0;
    int l_max = max(dfs(root->left, res), 0);
    int r_max = max(dfs(root->right, res), 0);
    res = max(res, root->val+l_max+r_max);
    return root->val+max(l_max,r_max);
}
};
