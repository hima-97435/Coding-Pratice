class Solution {
    int rr , cl ;

public:
    void solve(vector<vector<char>>& board) {
        rr = board.size();
        cl = board[0].size();
        for( int r=0;r<rr;r++){
            if(board[r][0] == 'O') capture(board,r,0);
            if(board[r][cl-1] == 'O') capture(board,r, cl-1);
        }
        for( int c=0;c<cl;c++){
            if(board[0][c] == 'O') capture(board,0,c);
            if(board[rr-1][c] == 'O') capture(board,rr-1, c);
        }
        for( int r =0;r<rr;r++){
            for( int c =0;c<cl;c++){
                if(board[r][c] == 'O') board[r][c] = 'X';
                else if(board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
    void capture(vector<vector<char>> & board, int r , int c){
        if(r<0 || c<0 || r>=rr || c>= cl || board[r][c] != 'O') return;
        board[r][c] = 'T';
        capture(board,r+1,c);
        capture(board,r-1,c);
        capture(board,r,c+1);
        capture(board,r,c-1);
        
        
    }
};
