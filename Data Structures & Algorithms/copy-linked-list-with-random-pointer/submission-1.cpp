/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    unordered_map<Node*, Node* > map;

public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        if(map.count(head)) return map[head];
        Node* cpy = new Node(head->val);
        map[head]= cpy;
        cpy->next= copyRandomList(head->next);
        cpy->random= map[head->random];
        return cpy;

    }
};
