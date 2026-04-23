class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for( int i=0;i<9;i++){
            vector<bool> rowset(9,false),colset(9,false),boxset(9,false);
            for( int j=0;j<9;j++){
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if (rowset[num]) return false;
                    rowset[num] = true;
                }
                if(board[j][i] != '.') {
                    int num = board[j][i] - '1';
                    if (colset[num]) return false;
                    colset[num] = true;
                }
                 int r = 3 * (i / 3) + j / 3;
                int c = 3 * (i % 3) + j % 3;

                if (board[r][c] != '.') {
                    int num = board[r][c] - '1';
                    if (boxset[num]) return false;
                    boxset[num] = true;
                }
                
            }
        }
        return true;

    }
};
