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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       return helper(preorder,0,preorder.size()-1, inorder, 0, inorder.size()-1);
        
    }
    TreeNode* helper(vector<int> & preorder , int ps, int pe , vector<int>&inorder , int is , int ie){
        if(ps>pe || is>ie) return nullptr;
        TreeNode* node = new TreeNode(preorder[ps]);
        int index = is;
        while(index <= ie){
            if(inorder[index] == preorder[ps]) break;
            index++;
        }
        int leftsize= index - is;
        node->left= helper(preorder, ps+1, ps+leftsize, inorder, is, index-1);
        node->right= helper(preorder, ps+leftsize+1, pe, inorder, index+1, ie);
        return node;
    }
};
