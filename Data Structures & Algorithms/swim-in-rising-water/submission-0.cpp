class Solution {
public:
int n;
vector<vector<int>> directions ={{0,1},{1,0},{0,-1},{-1,0}};
bool func(int limit , vector<vector<int>> grid){
    if(grid[0][0]> limit) return false;
    vector<vector<bool>> vs(n , vector<bool> (n, false));
    queue<pair<int , int>> q;
    q.push({0,0});
    vs[0][0] = true;
    while(!q.empty()) {
        auto [r,c] = q.front();
        q.pop();
        if(r == n-1 && c == n-1) return true;
        for(auto d: directions){
             int nr = r+d[0];
             int nc = c+d[1];
             if(nr>=0 && nr<n && nc>=0 && nc<n && !vs[nr][nc]){
                if(grid[nr][nc] <= limit){
                    vs[nr][nc] = true;
                    q.push({nr, nc});
                }
             }
        }

    }
    return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        int maxele = 0;
        for( int i=0;i<n;i++){
            for( int j=0;j<n;j++){
                 maxele = max(maxele, grid[i][j]);
            }
        }
        int low =0;
        int ans= maxele;
        int high=maxele;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(func(mid, grid)){
                ans= mid;
                high=mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};
