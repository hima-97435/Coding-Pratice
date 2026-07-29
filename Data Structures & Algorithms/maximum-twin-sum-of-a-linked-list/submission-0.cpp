/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> ans;
        ListNode* l1 = head;
        while(l1){
            ans.push_back(l1->val);
            l1=l1->next;
        }   
        int n = ans.size();
        int l =0, r = n-1;
        int maax = INT_MIN;
        while(l<=r){
            maax=max(maax,ans[l]+ans[r]);
            l++;
            r--;
        }
        return maax;
    }
};