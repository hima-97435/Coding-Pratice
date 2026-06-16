class Solution {
public:
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // if(matrix.empty() || matrix[0].empty()) return 0;
        int row = matrix.size();
        int col= matrix[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        int maxpath=0;
        for( int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                maxpath=max(maxpath,dfs(matrix,r,c,dp));
            }
        }
        return maxpath;
    }
    int dfs(vector<vector<int>>& matrix, int r, int c, vector<vector<int>>& memo){
        if(memo[r][c] != -1) return memo[r][c];

        int currentmax=1;
        for(auto &d: dir){
            int nr = r+d[0];
            int nc = c+d[1];
            if(nr>=0 && nc>=0 
            && nr<matrix.size() 
            && nc<matrix[0].size() 
            && matrix[nr][nc] > matrix[r][c]) {
                    currentmax=max(currentmax,1+dfs(matrix,nr,nc,memo));
            }
        }
        return memo[r][c]=currentmax;
    }
};
