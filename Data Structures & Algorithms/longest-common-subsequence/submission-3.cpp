class Solution {
public:
vector<vector<int>> dp;
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        dp.assign(m+1 , vector<int>(n+1,-1) );
        return helper(text1, text2, m , n);

    }
    int helper(string text1 , string text2, int i , int j){
        if( i == 0 || j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if (text1[i-1] == text2[j-1]) {
            return dp[i][j] = 1 + helper(text1, text2, i-1, j-1);
        } else {
            return dp[i][j] = max(
                helper(text1, text2, i, j-1),
                helper(text1, text2, i-1, j)
            );
        }
    }
    
};
