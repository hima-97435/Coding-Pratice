class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int m = board.size(), n = board[0].size();
        queue<pair<int , int>> q;
        vector<vector<bool>> vis(m , vector<bool>(n , false));
       for( int i=0;i<m ;i++){
        for( int j=0;j<n;j++){
            if((i == 0 || j ==0 || i == m-1 || j == n-1)&& board[i][j] == 'O'){
                vis[i][j] = true;
                q.push({i,j});
            }
        }
       } 
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    while(!q.empty()){
        auto[rr,cc] = q.front();
        q.pop();
        for(auto & d: directions){
            int r = rr+d[0];
            int c = cc+d[1];
            if(r>0 && r<m && c>0 && c<n && board[r][c] == 'O' && !vis[r][c]){
                vis[r][c]= true;
                q.push({r,c});
            }
        }
    }
    for( int i=0;i<m;i++){
        for( int j=0;j<n;j++){
            if(board[i][j] == 'O' && !vis[i][j]){
                board[i][j]='X';
            }
        }
    }

    }
};
