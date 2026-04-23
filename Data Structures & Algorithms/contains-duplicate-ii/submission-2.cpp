class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(set.count(nums[i])) return true;
            set.insert(nums[i]);
            if(set.size()>k) set.erase(nums[i-k]);
        }
        return false;
    }

};