class Solution {
public:
    unordered_map<int,int> memo;
    int dfs(int am, vector<int> & coins){
        if( am == 0) return 0;
        if(memo.find(am) != memo.end()) return memo[am];
        int res = INT_MAX;
        for( int coin: coins){
            if(am-coin>=0){
                int result = dfs(am-coin, coins);
                if(result !=INT_MAX) res = min(res, 1+result);

            }
        }
        memo [am]=res;
        return res;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int mincoins= dfs(amount, coins);
        // return mincoins == INT_MAX ?-1: mincoins;
        int n = coins.size();
        vector<int> dp (amount+1, amount+1 );
        dp[0]=0;
        for( int i=1;i<=amount;i++){
            for( int j =0;j<n;j++){
                if(coins[j]<=i) {
                    dp[i]=min(dp[i] , dp [i-coins[j]]+1);
                }
            }
        }
        return dp[amount]>amount?-1:dp[amount];
    }
};
