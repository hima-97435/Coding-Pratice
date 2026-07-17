class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<string>> dp(n+1,vector<string>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0) {dp[i][j]=str2.substr(0,j);}
                else if(j == 0) {dp[i][j]= str1.substr(0,i); }
                else if(str1[i-1] == str2[j-1]) {dp[i][j] = dp[i-1][j-1]+str1[i-1];}
                else {
                    dp[i][j]=dp[i-1][j].size()<dp[i][j-1].size()?
                    dp[i-1][j]+str1[i-1]: dp[i][j-1]+str2[j-1];
                }

            }
        }
        return dp[n][m];
    }
};