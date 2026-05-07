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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode dummy(0);
     dummy.next = head;
     ListNode* fast = &dummy;
     while(n>=0){
        fast= fast->next;
        n--;
     }
     ListNode* slow= &dummy;
     while(fast){
        fast= fast->next;
        slow= slow->next;
     }
     ListNode* nn = slow->next;
     slow->next= slow->next->next;
     delete nn;
     return dummy.next;
    }
};
