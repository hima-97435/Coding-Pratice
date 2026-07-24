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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = nullptr;
        ListNode* curnode = head;
        while(curnode){
            ListNode* temp = curnode->next;
            curnode->next = dummy;
            dummy = curnode;
            curnode=temp;
        }
        return dummy;
    }
};
