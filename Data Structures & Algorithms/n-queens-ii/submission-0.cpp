class Solution {
public:
    bool isSafe(int row, int col , vector<string> board, int n){
        for(int i=0;i<n;i++){
            if(board[i][col] == 'Q') return false;
        }
        int i = row, j = col;
        while(i>=0 and j>=0 ) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(i>=0 and j>=0 ){
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }
        return true;
    }
    int totalNQueens(int n) {
        vector<string> board(n, string(n,'.'));
        int ans =0;
        auto backtrack = [&](auto &&self, int row)-> void{
            if(row == n ) {
                ans++;
                return;
            }
            for(int i=0;i<n;i++){
                if(isSafe(row,i,board,n)){
                    board[row][i]='Q';
                    self(self,row+1);
                    board[row][i]='.';
                }
            }
        };
        backtrack(backtrack,0);
        return ans;
    }
};