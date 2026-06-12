class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = -prices[0];
        int sell =0;
        int cooldown = 0;
        for( int i=1;i<n;i++){
            int price = prices[i];
            int prevsell=sell;
            sell= max(sell, buy+price);
            buy= max(buy, cooldown-price);
            cooldown=max(cooldown,prevsell);

        }
        return max(sell,cooldown);
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
