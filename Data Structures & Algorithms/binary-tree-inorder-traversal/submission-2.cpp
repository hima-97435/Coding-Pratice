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
    void traversal(TreeNode* r){
        if(!r) return;

    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        auto traversal = [&](auto&&self, TreeNode* r) -> void{
            if(!r) return;
            self(self,r->left);
            ans.push_back(r->val);
            self(self,r->right);
        };
        traversal(traversal,root);
        return ans;
    }
};