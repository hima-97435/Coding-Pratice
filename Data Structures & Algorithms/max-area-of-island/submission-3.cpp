class DSU{
public:
vector<int> Parent, Size;
public:
DSU( int n ){
    Parent.resize(n);
    Size.resize(n);
    for( int i=0;i<n;i++){
        Parent[i]=i;
        Size[i]=1;
    }
}
int find( int node){
    if(node!=Parent[node]) {
        Parent[node]= find(Parent[node]);
    }
    return Parent[node];
}
void unionbysize( int u , int v){
    int pu = find(u);
    int pv = find(v);
    if(pu == pv) return;
    if(Size[pu] >= Size[pv]) {
        Size[pu]+=Size[pv];
        Parent[pv]=pu;
    }
    else {
        Size[pv]+=Size[pu];
        Parent[pu]=pv;
    }
    return;
}

};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int maxarea=0;
        for( int i=0;i<ROWS;i++){
            for( int j=0;j<COLS;j++){
                if(grid[i][j] == 1) maxarea=max(maxarea,dfs(grid,i,j));
            }
        }
        return maxarea;
    }
    int dfs(vector<vector<int>> & grid, int r, int c){
        if(r<0 || c<0 || r>=grid.size() || c>= grid[0].size() ||  grid[r][c] == 0) return 0;
        grid[r][c]=0;
        return 1+dfs(grid,r+1,c) +dfs(grid,r,c+1)+dfs(grid,r-1,c)+dfs(grid,r,c-1);
    }
};
