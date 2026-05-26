class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for( int i=0;i<n;i++){
            for( int j=0;j<m;j++){
                if(board[i][j] == word[0]) {
                    // word.erase(0,1);
                    if(dfs(board, word, i , j, m , n, 0 ) ) return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int i , int j, int m , int n, int index){
        if(word.size() == index) return true;
        if(i>=n || j>=m ||i<0 || j<0 || board[i][j] != word[index]) return false;
        
        
        char temp = board[i][j];
        board[i][j]='#';
        bool res = dfs(board, word, i, j-1, m , n, index+1) ||
                    dfs(board, word, i, j+1, m , n, index+1) ||
                    dfs(board, word, i-1, j, m , n, index+1) ||
                    dfs(board, word, i+1, j, m , n, index+1);
        board[i][j]= temp;
        return res;
    }
};
