class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int , int> count;
        for( int x: nums) count[x]=1+count[x];
        vector<vector<int>> vec(nums.size()+1);
        for( auto t: count) {
          vec[t.second].push_back(t.first);
        }
        vector<int> ans;
        for( int i= vec.size()-1;i>0;--i){
          for( int n : vec[i]){
            ans.push_back(n);
            if(ans.size() == k) return ans;
          }
        }
        return ans;
    }
};
