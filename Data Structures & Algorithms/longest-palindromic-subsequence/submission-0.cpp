class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        auto dfs = [&] (auto && self, int i , int j )->int{
            if(i>j) return 0;
            if( i == j) return 1;
            if(dp[i][j] != -1) return dp[i][j];
            if(s[i] == s[j]) dp[i][j]=self(self,i+1,j-1)+2;
            else dp[i][j]=max(self(self,i,j-1), self(self,i+1,j));
            return dp[i][j];
        };
        return dfs(dfs,0, n-1);
    }
};