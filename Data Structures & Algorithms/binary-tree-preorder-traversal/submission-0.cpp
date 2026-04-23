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
    void tarversal( TreeNode* r, vector<int> &an){
        if( r == NULL) return;
        an.push_back(r->val);
        tarversal(r->left,an);
        tarversal(r->right,an);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
         vector<int> ans;
        tarversal(root, ans);
        return ans;
    }
};