class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int freshorange =0 ;
        queue<pair<int , int>> q;
        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(grid[i][j] == 2) q.push({i,j}); 
                if(grid[i][j] == 1) freshorange++;

            }
        }
        if(freshorange == 0) return 0;
        int mins= 0;

        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            int x = q.size();
            bool flag= false;
            for( int i=0;i<x;i++){
            int rr = q.front().first;
            int cc = q.front().second;
            q.pop();
            for(auto  &d: directions ){
                int r = rr+d[0];
                int c = cc+d[1];
                if(r<0 || c<0 || r>=m || c>=n || grid[r][c] != 1) continue;
                grid[r][c] = 2;
                // result = max(result,grid[r][c]);
                freshorange--;
                q.push({r,c});
                flag= true;

                }
            }
            if(flag) mins++;
        }
        return freshorange == 0 ? mins:-1;
    }
};
