class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for( int x:  nums) mp[x]++;
        priority_queue<pair<int , int>, vector<pair<int , int>>, greater<pair<int , int>>> pq;
        for(auto & x : mp){
          pq.push({x.second,x.first});
          if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(pq.size() != 0){
          auto t = pq.top();
          ans.push_back(t.second);
          cout<<t.first<<" "<<t.second;
          cout<<endl;
          pq.pop();
        }
        return ans;
    }
};
