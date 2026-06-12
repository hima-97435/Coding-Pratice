class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector<vector<int>> dp(n+1, vector<int>(amount+1,0));
        vector<int> dp(amount+1,0);
        // for( int i=0;i<=n;i++) dp[i][0]=1;
        dp[0]=1;
        for(int x: coins){
            for( int i=x;i<=amount;i++){
                dp[i]+=dp[i-x];
            }
        }
        return dp[amount];
    }
};
