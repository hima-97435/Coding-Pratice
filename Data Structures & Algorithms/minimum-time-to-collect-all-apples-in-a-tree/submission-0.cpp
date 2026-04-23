class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
       vector<vector<int>> adj(n);
       for(const auto & edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
       } 
       return dfs(0,-1,adj,hasApple);
    }
    private:
    int dfs( int cur, int parent , vector<vector<int>> & adk , vector<bool> & hasapple){
        int time =0;
        for( int child : adk[cur]){
            if(child == parent) continue;
            int childt = dfs(child,cur, adk,hasapple);
            if(childt>0 || hasapple[child]) time+=2+childt;
        }
        return time;
    }
};