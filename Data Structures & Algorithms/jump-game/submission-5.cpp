class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return dfs(nums,0, dp);
    }

    bool dfs(vector<int> nums, int i, vector<int>& dp){
        if(dp[i]!=-1) return dp[i];
        if( i == nums.size()-1) return dp[i]=true;
        int end = min((int)nums.size()-1,i+nums[i]);
        for( int j=i+1;j<=end;j++){
            if(dfs(nums , j,dp)){
                dp[i]=true;
                return true;
            }
        }
        return dp[i]=false;
    }
};
