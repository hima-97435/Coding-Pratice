class MyHashMap {
public:
    vector<pair<int, int>> vec;
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
       for(auto & p: vec){
        if(p.first == key) {
            p.second = value; 
            return;
        }
       }
        vec.push_back({key, value});
    }
    
    int get(int key) {
        for(const auto &t: vec){
            if(t.first == key) return t.second;
        }
        return -1;
    }
    
    void remove(int key) {
        erase_if(vec,[key](const auto &p ){
            return p.first == key;
        });
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */