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
    int countComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        int res = n;
        for(auto & ed : edges){
            if(dsu.unionnodes(ed[0],ed[1])) res--;
        }
        return res;
    }
};
