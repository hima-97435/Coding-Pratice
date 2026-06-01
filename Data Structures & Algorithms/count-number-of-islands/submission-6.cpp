class Solution {
   public:
    vector<vector<bool>> visited;

    int numIslands(vector<vector<char>>& grid) {
        visited.assign(grid.size(), vector<bool>(grid[0].size(), false));
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    trvaersal(grid, visited, i, j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
    void trvaersal(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) return;
        if (visited[row][col] || grid[row][col] == '0') return;
        visited[row][col] = true;
        trvaersal(grid, visited, row + 1, col);
        trvaersal(grid, visited, row, col + 1);
        trvaersal(grid, visited, row - 1, col);
        trvaersal(grid, visited, row, col - 1);
        // cnt+=1;
    }
};
