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
        if(!node) return nullptr;
        unordered_map<Node*, Node*> oldtonew;
        queue<Node*> q;
        oldtonew[node]= new Node(node->val);
        q.push(node);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            for( Node * neigh : cur->neighbors){
                if(oldtonew.find(neigh )== oldtonew.end()) {
                    oldtonew[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                oldtonew[cur]->neighbors.push_back(oldtonew[neigh]);
            }
        } 
        return oldtonew[node];
    }
};
