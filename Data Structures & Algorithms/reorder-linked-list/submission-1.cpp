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
    void reorderList(ListNode* head) {
      if(!head || !head->next) return;
      ListNode* slow = head , * fast = head;
      while(fast&& fast->next) {
        slow= slow->next;
        fast= fast->next->next;
      }
      ListNode* prev = nullptr;
      ListNode* curr = slow->next;
      slow->next= nullptr;
      while(curr){
        ListNode* temp = curr->next;
        curr->next= prev;
        prev= curr;
        curr= temp;
      }
      ListNode* t1 = head;
      ListNode* t2= prev;
      while(t2){
        ListNode* tt1=t1->next;
        ListNode* tt2= t2->next;
        t1->next= t2;
        t2->next=tt1;
        t1=tt1;
        t2=tt2; 
      }
    }
};
