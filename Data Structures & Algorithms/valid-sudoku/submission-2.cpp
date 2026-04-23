class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<9;j++){
                 if(board[i][j] =='.') continue;
                 if(seen.count(board[i][j])) return false;
                 seen.insert(board[i][j]);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<9;j++){
                 if(board[j][i] =='.') continue;
                 if(seen.count(board[j][i])) return false;
                 seen.insert(board[j][i]);
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> seen;
            for(int j=0;j<3;j++){
                for(int k =0;k<3;k++){
                      int row = (i/3)*3+j;
                      int col = (i%3)*3+k;
                      if(board[row][col] == '.') continue;
                      if(seen.count(board[row][col])) return false;
                      seen.insert(board[row][col]); 
                }
            }
        }
        return true;
    }
};
