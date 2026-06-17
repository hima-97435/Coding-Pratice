class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return dfs(nums , 0 , dp);
    }
    int dfs(vector<int>&nums, int i, vector<int>&dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int minjump=1e9;
        int end =min((int)nums.size()-1,i+nums[i]);
        for(int j=i+1;j<=end;j++){
            int nextjump=dfs(nums,j, dp);
            if(nextjump!=1e9){
                minjump=min(minjump,1+nextjump);
            }
        }
        cout<<i<<" : "<<dp[i]<<endl;
        return dp[i]=minjump;

    }
};
