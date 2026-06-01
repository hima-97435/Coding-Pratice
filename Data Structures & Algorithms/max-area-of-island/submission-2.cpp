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
        DSU dsu(ROWS*COLS);
        int directions[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
        auto index  = [&]( int r, int c){
            return r*COLS+c;
        };
        for( int i=0;i<ROWS;i++){
            for( int j=0;j<COLS;j++){
                if(grid[i][j] == 1){
                    for(auto &d : directions){
                    int nr = i+d[0];
                    int nc = j+ d[1];
                    if(nr>=0 && nc>=0 && nr<ROWS&& nc<COLS && grid[nr][nc] == 1) {
                        dsu.unionbysize(index(i,j), index(nr, nc));
                    }        
                }
            }
                
            }
        }
        int maxarea= 0;
        for( int i=0;i<ROWS;i++){
            for( int j=0;j<COLS;j++){
                if(grid[i][j] == 1 ) {
                    int root = dsu.find(index(i,j));
                    maxarea=max(maxarea,dsu.Size[root]);
                }
            }
        }
        return maxarea;
    }
};
