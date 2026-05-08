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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ans;
        ListNode de(0);
        ListNode* maini= &de;
        for( auto & temp : lists){
            ListNode* t = temp;
            while(t){
            ans.push_back(t->val);
            t= t->next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode dummy;
        ListNode* curr = &dummy;
        for(int x: ans){
            ListNode* demo = new ListNode(x);
            curr->next = demo;
            curr= demo;
        }
        return dummy.next;
    }
};
