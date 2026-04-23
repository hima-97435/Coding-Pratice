class Solution {
    int n ;
    vector<vector<bool>> vis;
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
public:
    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vis= vector<vector<bool>> (n , vector<bool>(n , false));

        bool found = false;
        for( int i=0;i<n;i++){
            if(found) break;
            for( int j=0;j<n;j++){
                if(grid[i][j] == 1) {
                    dfs(grid,i,j);
                    found = true;
                    break;
                }
            }
        }
        return bfs(grid);
    }
    void dfs(vector<vector<int>> & grid, int r, int c){
        if(r<0 || c<0 || r>=n ||c>=n || grid[r][c] == 0 || vis[r][c]) return;
        vis[r][c] = true;
        for(auto & d: dir) dfs(grid,r+d[0],c+d[1]);

    }
    int bfs(vector<vector<int>> & grid){
        queue<pair<int, int>> q;
        for( int i=0;i<n;i++){
            for( int j=0;j<n;j++){
                if(vis[i][j] ) q.push({i,j});

            }
        }
        int res =0;
        while(!q.empty()){
            for( int i = q.size() ;i>0 ;i--){
                auto[r,c] = q.front();q.pop();
                for(auto & d: dir){
                    int curr= r+d[0],curc=c+d[1];
                    if(curr <0 || curc<0 || curr>=n || curc>=n || vis[curr][curc] ) continue;
                    if(grid[curr][curc] == 1) return res;
                    q.push({curr,curc});
                    vis[curr][curc] = true;
                 }
            }
            res++;
        }
        return res;
    }
};