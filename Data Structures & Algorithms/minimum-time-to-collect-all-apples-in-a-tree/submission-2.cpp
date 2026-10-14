class Solution {
public:

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            
        }
        int cnt =0;
        auto dfs = [&](auto&&self, int node, int parent)->bool{
            bool found = false;
            // if(hasApple[node]) cnt+=1;
            for(auto&n: adj[node]){
                if(n == parent) continue;
                if(self(self,n,node)) {
                    cnt+=2;
                    found=true;
                }
            }
            return found||hasApple[node];
        }; 
        dfs(dfs,0,0);
        return cnt;       
    }
};