class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto t: p ){
            adj[t[1]].push_back(t[0]);
            indegree[t[0]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            n--;
            for(int nxt : adj[cur]){
                indegree[nxt]--;
                if(indegree[nxt] == 0) q.push(nxt);
            }
        }
        return n == 0;
    }
};
