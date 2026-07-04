class DSU{
    public:
    vector<int> parent, Size;
    int components;
    DSU( int n){
        parent.resize(n+1);
        Size.assign(n,1);
        components=n;
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int find(int node){
        if(parent[node]!=node) parent[node]=find(parent[node]);
        return parent[node];
    }
    bool unionset(int u , int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        components--;
        if(Size[pu]>=Size[pv]){
            Size[pu]+=Size[pv];
            parent[pv]=pu;
        }
        else {
           Size[pv]+=Size[pu];
            parent[pu]=pv;     
        }
        return true;
    }
    int numofcomps(){
        return components;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) dsu.unionset(i,j);

            }
        }
        return dsu.numofcomps();
    }
};