class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orginalcolor= image[sr][sc];
        if(orginalcolor == color) return image;
        vector<vector<int>> directions = {{0,1},{1,0},{0,-1},{-1,0}};
        queue<pair<int , int>>q;
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            auto[r,c] = q.front();
            q.pop();
            
            for(auto d: directions) {
                int nr = r+d[0];
                int nc = c+d[1];
                if(nr>=0 && nc>=0 && nr<image.size() && nc<image[0].size() && image[nr][nc] == orginalcolor) {
                    image[nr][nc]=color;
                    q.push({nr,nc});
                } 
            }
        }
        return image;
    }
};