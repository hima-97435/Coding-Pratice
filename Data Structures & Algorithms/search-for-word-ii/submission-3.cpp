class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       int rows= board.size(), col = board[0].size();
       vector<string> res;
       for(string & w : words){
            bool flag= false;
            for( int r=0;r<rows && !flag;r++){
                for( int c=0;c<col;c++){
                    if(board[r][c] != w[0]) continue;
                    if(backtrack(board, r, c, w, 0)) {
                        res.push_back(w);
                        flag= true;
                        break;
                    }
                }
            }
       }
       return res;
    }
    bool backtrack(vector<vector<char>>& board, int r, int c, string & word, int i){
        if( i == word.size()) return true;
        if(r<0 || c<0 || r>=board.size() || c>= board[0].size() || board[r][c]!=word[i]) return false;
        board[r][c]='#';
        bool res = backtrack(board, r+1, c ,word, i+1) || 
                    backtrack(board, r, c+1 ,word, i+1) ||
                    backtrack(board, r-1, c ,word, i+1) ||
                    backtrack(board, r, c-1 ,word, i+1);
                    
        board[r][c]=word[i];
        return res;
    }
};
