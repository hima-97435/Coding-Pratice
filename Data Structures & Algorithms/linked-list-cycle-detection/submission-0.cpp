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
    bool hasCycle(ListNode* head) {
        ListNode* n1= head, * n2= head;
        while(n2 && n2->next){
            n1= n1->next;
            n2= n2->next->next;
            if(n1 == n2 ) return true;
        }
        return false;
    }
};
