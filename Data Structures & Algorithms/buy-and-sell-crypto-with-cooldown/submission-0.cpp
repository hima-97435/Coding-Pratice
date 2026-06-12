class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return dfs(0,1, prices, dp);
    }
    int dfs(int index, int buying , vector<int>& price, vector<vector<int>>&dp){
        if(index>=price.size()) return 0;
        if(dp[index][buying]!= -1) return dp[index][buying];
        if(buying){
            int skip = dfs(index+1,1,price, dp);
            int buy = -price[index]+dfs(index+1,0, price, dp);
            return dp[index][buying]=max(buy, skip);
        }
        else {
            int skip = dfs(index+1,0,price, dp);
            int buy = +price[index]+dfs(index+2,1, price, dp);
            return dp[index][buying]=max(buy, skip);   
        }
    }
};
