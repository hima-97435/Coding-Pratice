class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        auto dfs = [&](auto&&self, int index, int i , int j) -> bool{
            if(word.size() == index) return true;
            if(i<0 or i>=m or j<0 or j>=n or board[i][j] != word[index]) return false;
            char t = board[i][j];
            board[i][j]='#';
            bool res = self(self,index+1,i,j-1) or self(self,index+1,i,j+1 ) or self(self,index+1,i-1,j) or self(self,index+1,i+1,j);
            board[i][j]=t;
            return res;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(word[0] == board[i][j] ) {
                    if(dfs(dfs,0, i , j)) return true;
                }
            }
        }
        return false;
    }
};
