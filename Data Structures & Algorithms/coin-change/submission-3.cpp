class Solution {
    private:
    int back(vector<int> & coins , int amount){
        if(amount == 0 ) return 0;
        if(amount<0) return INT_MAX;
        int min_coin = INT_MAX;
        for( int coin : coins){
            int res = back(coins, amount-coin);
            if(res != INT_MAX){
                min_coin= min(min_coin,res+1);
            }
        }
        return min_coin;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        // int res = back(coins,amount);
        // return res == INT_MAX ?-1:res;
        vector< int > dp ( amount+1, amount+1);
        dp[0]=0;
        for( int i=1;i<=amount ;++i){
            for( int coin :  coins){
                if(i-coin >=0 ){
                    dp[i]= min(dp[i], dp[i-coin]+1);
                }
            }
        }
        return dp[amount]>amount ?-1:dp[amount];
    }
};
