class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for( int x:  nums){
        mp[x]++;    
        }
        //{{1,1},{2,2},{3,3}}
        priority_queue<pair<int, int>> pq;
        for(auto t : mp){
            pq.push({t.second,t.first});
        }
        vector<int> rrs;
        while(k--){
            
            rrs.push_back(pq.top().second);
            pq.pop();
        }
        return rrs;
    }
};
