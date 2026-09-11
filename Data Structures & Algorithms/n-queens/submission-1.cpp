class Solution {
public:
    bool issafe(int row, int col , vector<string> board, int n ){
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        int i= row, j = col;
        while( i>=0 and j>=0){
            if(board[i][j] == 'Q') return false;
            i--; j--;
        }
        i =row, j= col;
        while(i>=0 and j>=0 ){
            if(board[i][j] == 'Q' ) return false;
            i--;
            j++;
        }
        return true;

    }
    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n,string(n,'.'));
       vector<vector<string>> ans;
       auto backtrack = [&](auto &&self, int row) -> void{
        if(row == n) {ans.push_back(board); return ;}
        for(int i=0;i<n;i++){
            if(issafe(row,i, board,n)){
                board[row][i] ='Q';
                self(self,row+1);
                board[row][i]='.';
            }
        }
       };
       backtrack(backtrack,0);
       return ans;
    }
};
