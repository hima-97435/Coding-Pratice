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
    void traversal(TreeNode* root, vector<int> &pq, int k){
        if(!root) return;   
        pq.push_back(root->val);
        // if(pq.size() > k ) pq.top();
        traversal(root->left,pq,k);
        traversal(root->right,pq,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> pq;
        traversal(root, pq,k);
        sort(pq.begin(), pq.end());
        return pq[k-1];
    }
};
