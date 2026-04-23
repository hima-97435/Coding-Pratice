class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int , int> mp;
        int n = nums.size();

        for(int i=0;i<n;i++){
            int c1 = target-nums[i];
            if(mp.find(c1) != mp.end()){
                return {mp[c1],i};
            }
            mp.insert({nums[i],i});
        }
        return {};
    }
};
