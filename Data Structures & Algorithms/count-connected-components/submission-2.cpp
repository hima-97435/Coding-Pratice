class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n,1);  
        for(int i=0;i<n;i++) parent[i]=i;    
        auto findparent = [&](auto&&self, int u)->int{
            if(parent[u] == u) return u;
            return parent[u]=self(self,parent[u]);
        };
        auto unionnodes = [&]( int u , int v) ->bool{
            int pu = findparent(findparent,u);
            int pv = findparent(findparent,v);
            if(pu == pv) return false;
            if(rank[pv]>rank[pu]) swap(pv,pu);
            parent[pv]=pu;
            rank[pu]+=rank[pv];
            return true;
        };
        int ans = n;
        for(auto e: edges){
            if(unionnodes(e[0],e[1])) ans--;
        }
        return ans;
    }
};
