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
    int dfs(TreeNode* node, int currentmax){
        if(node == nullptr) return 0;
        int count =0;
        if(node->val >= currentmax) {
            count=1;
            currentmax = node->val;

        }
        return count+dfs(node->left,currentmax)+dfs(node->right,currentmax);
    }
};
