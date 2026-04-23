/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<Node* ,Node*> old;
        return dfs(old, node);
    }
    Node* dfs(map<Node*, Node*> & oldto, Node* node ){
        if(node == nullptr) return nullptr;
        if(oldto.count(node)) return oldto[node];
        Node* copy = new Node(node->val);
        oldto[node]=copy;
        for(Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(oldto,nei));
        }
        return copy;
    }
};
