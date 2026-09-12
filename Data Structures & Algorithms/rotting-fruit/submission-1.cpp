class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int , int>> q;
        int m = grid.size(), n = grid[0].size();
        int fresh =0 ;
        for(int i=0;i<m ;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j});
                if(grid[i][j] == 1) fresh++;
            }
        }
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int minutes =0;
        while(fresh>0 and !q.empty()){
            int length = q.size();
            for(int i=0;i<length;i++){
                auto[r,c]=q.front();
                q.pop();
                for(auto d: directions) {
                    int nr = r+d[0];
                    int nc = c+d[1];
                    if(nr>=0 and nc>=0 and nr<m and nc<n and grid[nr][nc] == 1){
                        q.push({nr,nc});
                        grid[nr][nc]=2;
                        fresh--;
                    }
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes: -1;
    }
};
