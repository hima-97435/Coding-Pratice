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
        ListNode* slow = head, *fast = head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while(second){
            ListNode* cur = second->next;
            second->next=prev;
            prev=second;
            second=cur;
        }
        ListNode* first = head;
        second = prev;
        int maax = 0;
        while(second){
            maax=max(maax,first->val+second->val);
            first=first->next;
            second=second->next;
        }
        return maax;
    }
};