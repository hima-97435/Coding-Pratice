class Solution {
public:
    int ans = INT_MIN;
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2,-1));

        auto dfs = [&] (auto&& self, int i, bool bought) -> int{
            if(i == prices.size())  return 0;
            if(dp[i][bought]!= -1) // we have check whether it is bought or not 
            {
                return dp[i][bought];
            }
            int res = self(self,i+1,bought);
            if(bought){
                res=max(res,prices[i]+self(self,i+1,false));
            }  
            else res=max(res,-prices[i]+self(self,i+1,true));
            return dp[i][bought]=res;
        };  
        return dfs(dfs,0, 0);

    }
};