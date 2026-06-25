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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* cur= head;
        ListNode* prev = dummy;
        while(cur != nullptr){
            cout<<cur->val<<" ";
            if(cur->val == val){
                prev->next=cur->next;
                ListNode* temp = cur;
                cur=cur->next;
                delete(temp);
            }
            else{
                prev=cur;
                cur=cur->next;
            }
            
        }
        return dummy->next;
    }
};