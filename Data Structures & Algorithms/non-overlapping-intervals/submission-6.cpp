class Solution {
public:
    vector<vector<int>> dp; 

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        dp.assign(n , vector<int> (n+1 , -1));
        return n-dfs(intervals,0,-1);
    }
    int dfs(vector<vector<int>>& intervals, int i , int prev){
        if( i == intervals.size()) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1]; 
        int res = dfs(intervals, i+1,prev);
        if(prev == -1 || intervals[prev][1]<=intervals[i][0]) {res=max(res,1+dfs(intervals,i+1,i));}
        return dp[i][prev+1]=res;
    }
};
