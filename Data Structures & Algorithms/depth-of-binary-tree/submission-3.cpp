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
void traversal(TreeNode* root, int cnt, int &ans){
    if(!root) return;
    // ans++;
    ans = max(ans, cnt);
    traversal(root->left,cnt+1, ans);
    traversal(root->right,cnt+1, ans);
}
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int x =0;
        traversal(root, 1, x);
        return x;
    }
};
