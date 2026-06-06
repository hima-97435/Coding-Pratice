class Solution {
    int findroot( int i , vector<int>& parent){
        if(parent[i] == i) return i;
        return parent[i]= findroot(parent[i], parent);
    }
    bool unionnodes(int u , int v, vector<int> & parent, vector<int> &Size){
        int pu = findroot(u, parent);
        int pv = findroot(v, parent);
        if(pu == pv) return false;
        if(Size[pu]>=Size[pv]){
            parent[pv]=pu;
            Size[pu]+=Size[pv];
        }
        else {
            parent[pu]=pv;
            Size[pv]+=Size[pu];
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent(edges.size()+1), Size(edges.size()+1,1);
        for( int i=1;i<=edges.size();i++) parent[i]=i;
        for(auto & e: edges){
            if(!unionnodes(e[0],e[1], parent, Size)) return e;
        }
        return {};
    }
};
