class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // if(s1.size()+s2.size() != s3.size()) return false;
        // return dfs(0,0,s1,s2,s3);
        int m = s1.size();
        int n = s2.size();
        if(m+n != s3.size()) return false;
        if(m<n) isInterleave(s2,s1,s3);
        vector<bool> dp(n+1, false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1]&&(s2[i-1] == s3[i-1]);
        }
        for( int i=1;i<=m;i++){
            dp[0]=dp[0]&&(s1[i-1] == s3[i-1]);
            for(int j=1;j<=n;j++){
                bool t1= dp[j] && (s1[i-1] == s3[i+j-1]);
                bool t2 = dp[j-1] && (s2[j-1] == s3[i+j-1]);
                dp[j]=t1||t2;
            }
        }
        return dp[n];
    }
    bool dfs( int i ,int j , string s1, string s2, string s3)
    {
        int k = i+j;
        if(k == s3.size()) return true;
        bool matchs1= false;
        bool matchs2=false;
        if(i<s1.size()&& s1[i] == s3[k]) {matchs1=dfs(i+1,j, s1,s2,s3);}
        if(j<s2.size()&& s2[j] == s3[k]) {matchs2=dfs(i,j+1, s1,s2,s3);}
        return matchs1||matchs2;
    }
};
