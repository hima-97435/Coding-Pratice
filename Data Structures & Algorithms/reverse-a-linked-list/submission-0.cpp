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
        vector<int> arr;
            ListNode * temp = head;
            while(temp){
                arr.push_back(temp->val);
                temp= temp->next;
            }
            ListNode * t1= head;
            for(int i=arr.size()-1;i>=0;i--){
                t1->val=arr[i];
                t1=t1->next;

            }
    return head;
    }

};
