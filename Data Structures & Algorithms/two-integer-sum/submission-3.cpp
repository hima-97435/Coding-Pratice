class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int , int> mp;
      for( int i=0;i<nums.size();i++){
        int t = target-nums[i];
        if(mp.find(t) != mp.end()){
          // mean map m h
          return {mp[t], i};

        }
        else mp.insert({nums[i],i});
      }  
      return {};
    }
};
