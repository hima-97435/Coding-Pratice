class DSU{
    vector<int> Parent, Size;
    int component;
    public:
    DSU( int n){
        component=n;
        Parent.resize(n+1);
        Size.resize(n+1);
        for( int i=0;i<=n;i++){
            Parent[i]=i;
            Size[i]=i;

        }
    }
    int find( int node){
        if(Parent[node] != node){
            Parent[node] = find(Parent[node]);
        }
        return Parent[node];
    }
    bool unionnodes(int u , int v){
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        // made a change at here
        if(Size[pu]>Size[pv]) swap(pu,pv);
        component--;
        Size[pu]+=Size[pv];
        Parent[pv]=pu;
        return true;
    }
    int components(){
        return component;
    }
};
class Solution {
    
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1) return false;
        DSU dsu(n);
        for(auto &edge : edges){
            if(!dsu.unionnodes(edge[0],edge[1])) return false;
        }
        return dsu.components() == 1;
    }
};
