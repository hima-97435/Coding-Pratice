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
    // once way could be use only simple traversal and making sure 
    // to keep adding values which are under the required range 
private:
    void tarversal(TreeNode* r , int l , int h, int &sum){
        if(!r) return;
        if(r->val>=l && r->val<=h) // make sense to add it
        {
            sum+=r->val;
        }
        tarversal(r->left, l , h , sum);
        tarversal(r->right, l , h , sum);
        
    }
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum =0;
        tarversal(root, low , high, sum);
        return sum;
    }
};