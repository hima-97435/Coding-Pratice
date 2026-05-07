class LRUCache {
public:
    vector<pair<int , int>> qq;
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
       for( int i=0;i<qq.size();i++){
        if(qq[i].first == key) {
            pair<int , int> tmp = qq[i];
            qq.erase(qq.begin()+i);
            qq.push_back(tmp);
            return tmp.second;
        }
       }
       return -1;
    }
    
    void put(int key, int value) {
        for( int i=0;i<qq.size();i++){
        if(qq[i].first == key) {
            // pair<int , int> tmp = qq[i];
            qq.erase(qq.begin()+i);
            qq.push_back({key, value});
            return ;
        }
       }
       if(qq.size() == cap) qq.erase(qq.begin());
       qq.push_back({key, value});
    }
};
