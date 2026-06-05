class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> visit(n, false);
        for(auto & e : edges){
            int x= e[0];
            int y= e[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        queue<pair<int , int>> q;
        q.push({0,-1});
        visit[0]= true;
        int vistedcount=0;
        while(!q.empty()){
            auto [curr,parent] = q.front();
            q.pop();
            vistedcount++;
            for( int neigh: adj[curr]){
                if(neigh == parent) continue;
                if(visit[neigh]) return false;
                visit[neigh]= true;
                q.push({neigh, curr}); 
            }
        }
        return vistedcount == n;
    }
};
