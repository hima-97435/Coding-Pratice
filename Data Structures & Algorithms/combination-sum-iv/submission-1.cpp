class Solution {
public:
unordered_map<int, int> mp;
    int combinationSum4(vector<int>& nums, int target) {
        mp[0]=1;
        return dfs(nums,target);
    }
    int dfs(vector<int>& nums , int target){
        cout<<target<<" ";
        if(mp.count(target)) return mp[target];
        int res =0;
        for(int z: nums) {
            if(target<0) break;
            res+=dfs(nums,target-z);
        }
        mp[target]=res;
        return res;
    }
};