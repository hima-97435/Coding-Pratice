class Solution {
public:

vector<vector<int>> directions ={{0,1},{1,0},{0,-1},{-1,0}};

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n , vector<bool>(n , false));
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>> > pq;
        pq.push({grid[0][0],0,0});
        vis[0][0]= true;
        while(!pq.empty()){
            auto cur = pq.top();
            pq.pop();
            int time = cur[0];
            int r = cur[1];
            int c = cur[2];
            if( r == n-1 && c == n-1) return time; 
            for(auto d : directions){
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=0 && nc>=0 && nc<n && nr<n && !vis[nr][nc]){
                    vis[nr][nc] = true;
                    int ttime = max(time, grid[nr][nc]);
                    pq.push({ttime,nr,nc});
                }
            }
        }
        return 0;
    }
};
