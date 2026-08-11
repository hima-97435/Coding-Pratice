class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    //    Apparently it is simple question 
    //    it just need check it is valid or not 
    //    dont think dfs and all simple chekcing
        for( int row =0;row<9;row++){
            unordered_set<char> seen;
            for( int i=0;i<9;i++) {
                if(board[row][i] == '.') continue;
                if(seen.count(board[row][i])) return false;
                seen.insert(board[row][i]);
            }
        }
        for( int col =0;col<9;col++){
            unordered_set<char> seen;
            for( int i=0;i<9;i++) {
                if(board[i][col] == '.') continue;
                if(seen.count(board[i][col])) return false;
                seen.insert(board[i][col]);
            }
        }
        for( int sq=0;sq<9;sq++){
            unordered_set<char> seen;
            for( int i=0;i<3;i++){
                for( int j=0;j<3;j++){
                    int r = (sq/3)*3+i;
                    int c = (sq%3)*3+j;
                    if(board[r][c] == '.') continue;
                    if(seen.count(board[r][c]) ) return false;
                    seen.insert(board[r][c]);
                }
            }
        }
        return true;
    }
};
