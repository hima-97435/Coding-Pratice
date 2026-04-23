class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // do it with map.
       unordered_map<int , int> mp;
       for( int x: nums) mp[x]++;
       vector<pair<int, int>> mm;
       for(auto& p : mp){
        mm.push_back({p.second, p.first});
       }
       sort(mm.rbegin(),mm.rend());
       vector<int> res;
       for( int i=0;i<k;i++){
        res.push_back(mm[i].second);
       }
       return res;
    }
};
