class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        queue<pair<int , int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1 ) and board[i][j] == 'O') {
                    visit[i][j]=true;
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [ r,c] = q.front();
            q.pop();
            for(auto d: direction){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=0 and nc>=0 and nr<m and nc<n and board[nr][nc] == 'O' and !visit[nr][nc]){
                    visit[nr][nc]= true;
                    q.push({nr,nc});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O' and !visit[i][j]) board[i][j]= 'X';
            }
        }
    }
};
