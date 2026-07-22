class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        auto dfs = [&](auto&&self, int i, int j) -> int{
            if(i == n || j == m )  return 0;
            if(dp[i][j] != -1) return dp[i][j];
            if(text1[i] == text2[j]) return dp[i][j]=1+self(self,i+1,j+1);
            return dp[i][j]=max(self(self,i,j+1), self(self,i+1,j));
        };
        return dfs(dfs,0,0);
    }
};
