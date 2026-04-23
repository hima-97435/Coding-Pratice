class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map optimised;
        // see for now being brute force was using extra loop ( O(N^2)).
        // but what if we store wahat values are present then 
        // it could be done in 1 loop.
        unordered_map<int , int> mp;
        for(int i=0;i<nums.size();i++){
          int need = target-nums[i];
          if(mp.find(need) == mp.end()) {
            // not in map
            mp[nums[i]]=i;
          }
          else {
            return {mp[need], i};
          }
        }
        return {-1,-1};
    }
};
