class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> frq;
        for( int x: nums) frq[x]++;
          priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto& [num, count] : frq) {
            pq.push({count , num});
            if(pq.size() > k ) pq.pop();
        }
        
        vector<int> res;
        // for( int i=0;
        // return res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();


        }
        // reverse(res.begin(),res.end());
        return res;
    }
};
