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
     ListNode* reversell(ListNode* head){
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(cur != nullptr){
            ListNode* nextnode = cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextnode;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            fast = fast->next->next;
            slow= slow->next;
        }
        ListNode* second = reversell(slow);
        ListNode* first = head;
        while(first && second) {
            if(first->val != second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};