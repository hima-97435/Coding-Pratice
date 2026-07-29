/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* l1= headA, * l2 = headB;
        while(l1!=l2){
            if(l1 &&l2) cout<<l1->val<<" "<<l2->val<<endl;
            l1=l1?l1->next:headB;
            l2=l2?l2->next:headA;
        }
        return l2;
    }
};