class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m<n) return 0;

        vector<int> dp(n+1,0);
        dp[n]=1;
        for( int i=m-1;i>=0;i--){
            for( int j=0;j<=n;j++){
                // dp[i][j]=dp[i+1][j];
                if(s[i] == t[j] ) dp[j]=dp[j]+dp[j+1];
            }
        }
        return dp[0];
    }
};
