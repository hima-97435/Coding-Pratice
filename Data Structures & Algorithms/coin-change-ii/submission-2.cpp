class Solution {
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size()+1, vector<int> (amount+1,-1));
        auto dfs = [&] (auto &&self, int i, int target)->int{
            if(target == 0) return 1;
            if(i>=coins.size()) return 0;
            if(dp[i][target] != -1) return dp[i][target];
            int res=0;
            if(coins[i]<=target) {
                res=self(self,i+1,target);
                res+=self(self,i,target- coins[i]);
            }
            return dp[i][target]=res;
        };
        return dfs(dfs,0,amount);
    }
};
