class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();
        vector<int> rowcnt(ROWS, 0), colcnt(COLS,0);
        for( int r=0;r<ROWS;r++){
            for( int c =0 ;c<COLS;c++){
                if(grid[r][c] == 1) {
                    rowcnt[r]++;
                    colcnt[c]++;
                }
            }
        }
        int res =0;
        for( int r=0;r<ROWS;r++){
            for( int c =0;c<COLS;c++){
                if(grid[r][c] == 1 && max(rowcnt[r], colcnt[c]) > 1) res++;
            }
        }
        return res;
    }
};