class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        for( int x: nums) mp[x]=1+mp[x];
        vector<vector<int>> freq(nums.size()+1);
        for(auto &p: mp){
          freq[p.second].push_back(p.first);
        }
        vector<int> ans;
        for(int i=nums.size();i>=0;i--){
          for(int n : freq[i]){
            ans.push_back(n);
            if(ans.size() == k) return ans;
          }
        }
        return ans;

    }
};
