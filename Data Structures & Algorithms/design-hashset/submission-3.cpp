class MyHashSet {
    private:
    struct Node{
        int key;
        Node* next;
        Node(int k ) : key (k) , next (nullptr ) {}
    };
    vector<Node*> set;
    int hash( int k) {
        return k % set.size();
    }
public:
    MyHashSet() {
        set.resize(10000);
         for(auto& bucket : set){
            bucket = new Node(0);

         }
    }
    
    void add(int key) {
        Node* cur = set[hash(key)];
        while(cur->next){
            if(cur->next->key == key) return;
            cur = cur->next;
        }
        cur->next = new Node(key);
    }
    
    void remove(int key) {
        Node* cur = set[hash(key)];
        while(cur->next){
            if(cur->next->key == key) {
                Node* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                return;

            }
            cur = cur->next;
        }
        
    }
    
    bool contains(int key) {
        Node* cur = set[hash(key)];
        while(cur->next){
            if(cur->next->key == key) {
                
                return true;

            }
            cur = cur->next;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */