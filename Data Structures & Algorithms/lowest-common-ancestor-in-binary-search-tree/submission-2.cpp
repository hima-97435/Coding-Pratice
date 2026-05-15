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
bool possible(TreeNode* root, TreeNode*p ){
    if(!root) return false;
    if( root == p) return true;
    return possible(root->left,p) || possible(root->right,p);

}
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // what are the possible answers for it 
        // for sure the nodes which can reach both p and q
        if( !root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p , q);
        TreeNode* r = lowestCommonAncestor(root->right, p , q);
        if(l && r) return root;
        return l?l:r;
    }
};
