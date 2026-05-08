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
private:
ListNode* reverseList(ListNode* head) {
        ListNode* temp = nullptr;
        while(head){
            ListNode* curr = head;
            head= head->next;
            curr->next = temp;
            temp=curr;
            curr= head;
        }
        return temp;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* node = head;
       int count =0;
       while(count<k){
        if(!node) return head;
        node = node->next;
        count++;
       }
       ListNode* nexti = reverseKGroup(node, k);
       ListNode*curr= head;
       ListNode* prev = nexti;
       for( int i=0;i<k;i++){
        ListNode* nextnode= curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
       }
       return prev;
    }
};
