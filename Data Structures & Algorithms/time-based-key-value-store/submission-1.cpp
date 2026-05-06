class TimeMap {
    unordered_map<string , vector<pair<int , string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& val = mp[key];
        int l =0 , r=val.size()-1;
        string res ="";
        while(l<=r){
             int m = l+(r-l)/2;
             if(val[m].first<=timestamp){
                res=val[m].second;
                l=m+1;
             }
             else r=m-1;
        }
        return res;
    }
};
