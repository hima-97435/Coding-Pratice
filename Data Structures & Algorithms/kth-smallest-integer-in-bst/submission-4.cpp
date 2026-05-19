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
    int result =-1;
    int cnt =0;
    void traversal(TreeNode* root, int k){
        if(!root || cnt>=k) return ;
        traversal(root->left,k);
        cnt++;
        if(cnt == k ){
            result= root->val;
            return;
        }
        traversal(root->right,k);

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        cnt =0;
        traversal(root, k );
        return result;
    }
};
