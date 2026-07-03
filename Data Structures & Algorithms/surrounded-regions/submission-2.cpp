class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n , false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if( (i ==0|| j == 0|| i == m-1 || j == n-1) && board[i][j] == 'O') {
                    vis[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>  directions = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!q.empty()){
            auto[r,c]=q.front();
            q.pop();
            for(auto &d: directions){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=0 && nc>=0 && nr<m && nc<n && board[nr][nc] == 'O' && !vis[nr][nc]){
                    vis[nr][nc]= true;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j]='X';
                }
            }
        }
    }
};
