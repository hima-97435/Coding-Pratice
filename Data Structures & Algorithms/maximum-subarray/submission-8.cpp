class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        return dfs(0,false, nums,dp);
    }
    int dfs(int i, bool flag , vector<int>& nums, vector<int> &dp){
        if( i == nums.size()-1) return flag?dp[i]=max(0, nums[i]):dp[i]=nums[i];
        // 0 here menat stpping the array
        if(flag) return dp[i]= max(0,nums[i]+dfs(i+1,true, nums,dp));
        else return dp[i]= max(dfs(i+1,false,nums,dp),nums[i]+dfs(i+1,true,nums,dp));
    }
};
