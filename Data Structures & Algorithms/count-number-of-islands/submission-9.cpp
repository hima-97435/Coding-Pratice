class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
        int R = grid.size(), C= grid[0].size();
        int island =0;
        auto bfs = [&]( int r, int c) -> void{
            queue<pair<int, int>> q;
            grid[r][c]='0';
            q.push({r,c});
            while(!q.empty()){
                auto [row, col] = q.front();
                q.pop();
                for(auto d : directions){
                    int nr = row+d[0];
                    int nc = col+d[1];
                    if(nr>=0 and nc>=0 and nr<R and nc<C and grid[nr][nc] == '1'){
                        q.push({nr,nc});
                        grid[nr][nc]='0';
                    }
                }
            }
        };
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(grid[i][j] == '1') {
                    bfs(i,j);
                    island++;
                }
            }
        }
        return island;
    }
};
