class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for( int x: nums) mp[x]++;
        vector<pair<int , int>> vec ;
        for( auto t : mp){
          vec.push_back({t.second, t.first});

        }
        sort(vec.rbegin(), vec.rend());
        vector<int> ans;
        for(auto t: vec ){
          cout<<t.first<<" "<<t.second;
          cout<<endl;
          if(ans.size()==k) break;
          ans.push_back(t.second);
        }
        return ans;
    }
};
