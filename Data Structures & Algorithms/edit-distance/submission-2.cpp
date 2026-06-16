class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        // if(m<n) return 0;

        vector<int> dp(n+1,0);
        for( int j=0;j<=n;j++) dp[j]=n-j;
        for(int i=m-1;i>=0;i--){
            int dgg= dp[n];
            dp[n]=m-i;

            for(int j=n-1;j>=0;j--){
                int prv = dp[j];
                if(word1[i] == word2[j]) {
                    dp[j]=dgg;
                }
                else {
                    dp[j]=1+min({dgg,dp[j],dp[j+1]});
                }
                dgg=prv;
            }
        }
        return dp[0];
    }
};
