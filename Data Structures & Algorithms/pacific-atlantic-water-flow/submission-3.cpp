class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> ans;
        if(heights.empty()) return ans;

        queue<pair<int, int>> pa;
        queue<pair<int, int>> ap;
        vector<vector<bool>> vispa(m , vector<bool>(n , false));
        vector<vector<bool>> visap(m , vector<bool>(n , false));
        for( int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if( i == 0 || j == 0) {
                    vispa[i][j]= true;
                    pa.push({i,j});
                }
                if( i == m-1 || j == n-1) {
                    visap[i][j]= true;
                    ap.push({i,j});
                }
            }
        }
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        auto bfs = [&](queue<pair<int , int>> q, vector<vector<bool>> & vec){
           while(!q.empty()){
            auto[rr,cc] = q.front();
            q.pop();
            for(auto & d: directions){
                int r = rr+d[0];
                int c = cc+d[1];
                if(r<0 || c<0 || r>=m || c>=n) continue;
                if(!vec[r][c] && heights[r][c] >= heights[rr][cc]) {
                    vec[r][c]= true;
                    q.push({r,c});
                }

            }
           }
        };
        bfs(pa,vispa);
        bfs(ap,visap);
        for(int i=0;i<m;i++){
            for( int j=0;j<n;j++){
                if(vispa[i][j] && visap[i][j]) ans.push_back({i,j});
            }
        }
        return ans;

        
    }
};
