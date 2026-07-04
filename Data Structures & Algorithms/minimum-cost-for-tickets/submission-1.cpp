class Solution {
    
public:
    vector<int> dp;
    int dfs( int i , vector<int>& days, vector<int>&cost){
        if( i == days.size() ) return 0;
        if(dp[i] != -1) return dp[i];
        dp[i] = INT_MAX;
        int index =0, j=i;
        for(int d :{1,7,30}){
            while(j<days.size() && days[j]<days[i]+d) j++;
            dp[i]=min(dp[i],cost[index]+dfs(j, days,cost));
            index++;
        }
        return dp[i];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        dp=vector<int> (days.size(),-1);
        return dfs(0,days,costs);
    }
};