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
        int mincoins= dfs(amount, coins);
        return mincoins == INT_MAX ?-1: mincoins;
    }
};
