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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        // int size = q.size();
        // int level =0;
        // for( int i=0;i<=size;i++){
        //     TreeNode* temp = q.front();
        //     q.pop();
        //     while(!q.empty()){
        //         if(temp->left!= nullptr) q.push(temp->left);
        //         if(temp->right != nullptr) q.push(temp->right);
        //     }
        //     level++;
        // }
        int level =0;
        while(!q.empty()){
            int size = q.size();
            for( int i=0;i<size;i++){
                TreeNode* nq = q.front();
                q.pop();
                if(nq->left != nullptr) q.push(nq->left);
                if(nq->right != nullptr) q.push(nq->right);
                
            }
            level ++;
        }
        return level;
    }
};
