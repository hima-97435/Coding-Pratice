class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mp;
        mp[0]=-1;
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
            int r = total%k;
            if(mp.find(r) == mp.end()) mp[r] = i;
            else if(i-mp[r]>1) return true;
        }
        return false;
    }
};