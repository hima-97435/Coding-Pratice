class MyHashMap {
    static const int SIZE = 1009; // prime number
    vector<vector<pair<int,int>>> buckets;
public:
    MyHashMap() : buckets(SIZE) {}

    int hash(int key) { return key % SIZE; }

    void put(int key, int value) {
        int h = hash(key);
        for (auto& [k,v] : buckets[h])
            if (k == key) { v = value; return; }
        buckets[h].push_back({key, value});
    }

    int get(int key) {
        int h = hash(key);
        for (auto& [k,v] : buckets[h])
            if (k == key) return v;
        return -1;
    }

    void remove(int key) {
        int h = hash(key);
        auto& bucket = buckets[h];
        bucket.erase(remove_if(bucket.begin(), bucket.end(),
                               [&](auto& p){ return p.first == key; }),
                     bucket.end());
    }
};
