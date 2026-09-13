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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* lprev = &dummy;
        ListNode* cur = head;
        for(int i=0;i<left-1;i++){
            lprev=cur;
            cur=cur->next;
        }
        ListNode* prev= nullptr;
        for(int i=0;i<right-left+1;i++){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev=cur;
            cur=nxt;
        }
        lprev->next->next=cur;
        lprev->next = prev;
        return dummy.next;
    }
};