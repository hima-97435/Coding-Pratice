class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> frq;
        for( int x: nums) frq[x]++;
        vector<pair<int, int>> arr( frq.begin(),frq.end());
        sort(arr.begin(),arr.end(),
        [] (auto &a , auto &b) { return a.second >b.second;});

        vector<int> res;
        for( int i=0;i<k;i++) res.push_back(arr[i].first);
        return res;
    }
};
