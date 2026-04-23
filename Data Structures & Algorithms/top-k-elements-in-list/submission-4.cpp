class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> res;
       for( int num: nums) mp[num]++;
       vector<pair<int,int>> arr;
       for( const auto & pair: mp) arr.push_back({pair.second,pair.first});
       sort(arr.rbegin(),arr.rend());
       for( int i=0;i<k;i++) {
        res.push_back(arr[i].second);
       }
       return res;
    }
};
