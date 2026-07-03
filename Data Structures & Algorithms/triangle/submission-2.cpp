class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n =  triangle.size();
        int m =  triangle[0].size();
        vector<vector<int>> memo(n, vector<int>(0));
        int INF = INT_MAX;
        for( int r =0;r<triangle.size();r++) {
            memo[r].resize(triangle[r].size(),INF);
        }
        return dfs(0,0,triangle,memo);
    }
    int dfs( int row,int col,vector<vector<int>>&triangle,vector<vector<int>>& memo){
        if(row>= triangle.size()) return 0;
        if(memo[row][col] !=INT_MAX) return memo[row][col];
        return memo[row][col]=triangle[row][col]+min(dfs(row+1,col,triangle,memo),dfs(row+1,col+1,triangle,memo));
    }
};