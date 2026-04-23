class Solution {
    vector<pair<int , int >> dire ={{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rw = heights.size();
        int col= heights[0].size();
        vector<vector<bool>> pacif(rw,vector<bool>(col,false));
        vector<vector<bool>> att(rw,vector<bool>(col,false));

        for( int c=0;c<col;c++){
            dfs(0,c,pacif,heights); // 1 row ka 
            dfs(rw-1,c,att,heights);
        }
        for(int r=0;r<rw;r++){
            dfs(r,0,pacif,heights); // 1 row ka 
            dfs(r,col-1,att,heights);            
        }
        vector<vector<int>> res;
        for( int i=0;i<rw;i++){
            for( int j =0;j<col;j++){
                if(pacif[i][j] && att[i][j]) res.push_back({i,j});
            }
        }
        return res;

    }
    void dfs (int r , int c , vector<vector<bool>> & ocean , vector<vector<int>>  heights){
        ocean[r][c]=true;
        for(auto [dr,dc]: dire){
            int nr = r+dr;
            int nc = c+dc;
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() &&  !ocean[nr][nc] && heights[nr][nc]>= heights[r][c]){
                dfs(nr,nc, ocean , heights);
            }
        }
    }
};
