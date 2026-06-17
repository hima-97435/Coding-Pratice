class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<bool> dp(n+1, false);
        dp[n]= true;
        for( int j=n-2;j>=0;j-= 2){
            if(p[j+1] == '*') dp[j]=dp[j+2];
        }
        for(int i=m-1;i>=0;i--){
            int prevdiagonal=dp[n];
            dp[n]=false;
            for(int j=n-1;j>=0;j--){
                int nextdiagonal=dp[j];
                bool current= (s[i] == p[j] || p[j] == '.');
                if(j+1<p.size() && p[j+1] == '*'){
                    bool skip = dp[j+2];
                    bool stretch= current&&dp[j];
                    dp[j]=skip|| stretch;
                }
                else{
                    dp[j]=current&&prevdiagonal;
                }
            prevdiagonal=nextdiagonal;
            }
        }
        return dp[0];
    }
    bool dfs(int i , int j , string s , string p, vector<vector<int>>& memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(j == p.size() ) return memo[i][j] = (i == s.size());
        bool current = (i<s.size() && (s[i] == p[j]|| p[j] == '.'));
        if(j+1<p.size() && p[j+1] == '*'){
            bool shrink = dfs(i,j+2,s,p,memo);
            bool stretch = current&&dfs(i+1,j,s,p,memo);
            return memo[i][j]=(shrink||stretch);

        }
        return memo[i][j]=(current&&dfs(i+1,j+1,s,p,memo));
    }
};
// aa *b
// *--> kuch bhi laga lo
