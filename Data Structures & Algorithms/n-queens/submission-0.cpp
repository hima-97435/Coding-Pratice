class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
      vector<string> board(n, string(n,'.'));
      vector<vector<string>> ans;
      backtrack(0,n,board,ans);
      return ans;
    }
    void backtrack(int row, int n , vector<string> & board, vector<vector<string>>& ans){
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++){
            if(issafe(row, i , board, n)){
                board[row][i]='Q';
                backtrack(row+1,n, board, ans);
                board[row][i]='.';
            }
        }
        
    }
    bool issafe(int row, int col , vector<string>& board, int n){
        for( int i=0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        int i=row, j= col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q' ) return false;
            i--;
            j--;
        }
        i=row, j= col;
        while(i>=0 && j>=0){
            if(board[i][j] == 'Q' ) return false;
            i--;
            j++;
        }
        return true;
        
    }
};
