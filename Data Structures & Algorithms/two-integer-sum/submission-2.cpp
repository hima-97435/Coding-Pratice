class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for( int i=0;i<n;i++) {
            int compilment = target-nums[i];
            auto it = mp.find(compilment);
            if(it != mp.end()){
                // value exist
                return {mp[compilment],i};
            }
            else {
                mp.insert({nums[i],i});
            }
        }
        return {};
    }
};
