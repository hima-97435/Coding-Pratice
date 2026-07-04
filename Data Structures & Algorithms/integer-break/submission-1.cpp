class Solution {
public:
unordered_map<int , int> dp;
    int integerBreak(int n) {
        dp[1]=1;
        return dfs(n, n);
    }
    int dfs( int n, int og){
        if(dp.find(n) != dp.end()) return dp[n];
        int res = (n == og) ? 0: n;
        for(int i=1;i<n;i++) {
            int val=dfs(i,og)*dfs(n-i,og);
            res=max(res,val);
        }
        return dp[n]=res;
    }
};