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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<pair<TreeNode* , TreeNode*>> st;
        st.push({p,q});
        while(!st.empty()){
            auto [n1,n2] = st.top();
            st.pop();
            if(!n1 && !n2) continue;
            if(!n1 || !n2 || n1->val != n2->val) return false;
            st.push({n1->left, n2->left});
            st.push({n1->right, n2->right});
        }
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;
        if(isSameTree(root, subRoot)) return true;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right, subRoot));
    }
    
};
