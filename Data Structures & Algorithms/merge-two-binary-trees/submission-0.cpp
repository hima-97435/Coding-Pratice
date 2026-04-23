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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        return dfs(root1,root2);
    }
    // can be seen in this way right , we store all values in root 1 ( tree1)
    // and if we have to nodes present like node exist then we simply add there value and store them in root1
    // if not then we simply check if node is present in root1 
    // if yes then move on to see other nodes
    // if not then add new node and make a link bw current node and node present in the root2( trre2)
    TreeNode* dfs(TreeNode* p , TreeNode* q){
        if(!p) return q;
        if(!q) return p;
        p->val+=q->val;
        p->left=dfs(p->left,q->left);
        p->right=dfs(p->right,q->right);
        return p;
    }
};