class Solution {
public:
    vector<double> dp;
    double new21Game(int n, int k, int maxPts) {
        dp.resize(k,-1.0);
        return dfs(0,n,k,maxPts);
    }
private:
    double dfs(int score, int n, int k , int maxpts){
        if(score>=k) return score<=n?1.0:0.0;
        if(dp[score] != -1.0) return dp[score];
        double prob =0;
        for(int i=1;i<=maxpts;i++) prob+=dfs(score+i,n,k,maxpts);
        dp[score]=prob/maxpts;
        return dp[score];
    }
};