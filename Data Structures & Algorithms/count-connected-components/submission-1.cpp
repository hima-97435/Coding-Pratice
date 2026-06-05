class Solution {
    int findroot(int i , vector<int>& parent){
        if(parent[i] == i) return i;
        return parent[i]=findroot(parent[i], parent);
    }
    bool unionodes( int u , int v, vector<int>&parent,vector<int>& Size){
        int pu=findroot(u, parent);
        int pv= findroot(v, parent);
        if(pu == pv ) return false;
        if(Size[pu]>=Size[pv]){
            parent[pv]=pu;
        }
        else {
            parent[pu]=pv;
        }
        return true;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> Size(n,0);
        for( int i=0;i<n;i++) parent[i]=i;
        int component=n;
        for(auto & e: edges){
            if(unionodes(e[0],e[1],parent,Size)) component--;
        }
        return component;
    }
};
