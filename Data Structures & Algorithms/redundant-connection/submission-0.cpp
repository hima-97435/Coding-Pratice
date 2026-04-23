class Solution {
// I beleive logic. is quit straight forward.
// we need to maintain a visted array and if 
// we see edge already there than we can simply remove that edge.
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);
        for(const auto& e : edges){
            int u = e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            vector<bool> vis(n+1,false);
            if(dfs(u,-1,adj, vis)) return {u,v};
        }
        return {};

    }
private:
    bool dfs(int node, int parent, 
    vector<vector<int>> &adj,   vector<bool> &vis )
    {
        if(vis[node]) return true;
        vis[node] = true;
        for( int n : adj[node]){
            if(n == parent) continue;
            if(dfs(n, node, adj, vis)) return true;

        }
        return false;
    }
};
