class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        auto dfs = [&](auto &&self, int i , int j) ->int{
            if( i == n) return 0;
            if(dp[i][j+1] != -1) return dp[i][j+1];
            int res = self(self,i+1,j);
            if(j == -1 || nums[j]<nums[i]) res=max(res,1+self(self,i+1,i));
            return dp[i][j+1]=res;
        };
        return dfs(dfs,0,-1);
    }
};
