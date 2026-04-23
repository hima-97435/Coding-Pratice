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
        ListNode* temp= nullptr;
        while(head ){
            // dono way
            // like move and then mark next
            // okayy 
            ListNode* t = head->next;
            head->next=temp;
            temp=head;
            head =t;

        }
        return temp;


        // [0,1,2,3]
        // let 0 as 
    }
};
