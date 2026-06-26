class MyHashMap {
private:
    int BUCKET_SIZE = 14003;
    vector<vector<pair<int, int>>> vec;
    int gethash(int key) {return key%BUCKET_SIZE;}
public:

    MyHashMap() {
        vec.resize(BUCKET_SIZE);
    }
    
    void put(int key, int value) {
       int index = gethash(key);
       for(auto & t : vec[index]){
        if(t.first == key) {
            t.second=value;
            return;
        }
       }
       vec[index].push_back({key,value});
    }
    
    int get(int key) {
       int index = gethash(key);
       for(auto & t : vec[index]){
        if(t.first == key) {
            return t.second;
        }
       }
       return -1;
    }
    
    void remove(int key) {
        int index = gethash(key);
        auto &tt = vec[index];
        for(auto it = tt.begin(); it!= tt.end();++it) {
            if(it->first == key) {tt.erase(it); return;}
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */