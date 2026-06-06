class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto& e: times){
            int u =e[0];
            int v =e[1];
            int t = e[2];
            adj[u].push_back({v,t});

        }
        vector<int> dis(n+1, INT_MAX);
        dis[k]=0;
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto[currtime, curr] = pq.top();
            pq.pop();
            if(currtime> dis[curr]) continue;
            for(auto & n : adj[curr]){
                int nextnode=n.first;
                int time = n.second;
                if(currtime+time<dis[nextnode]) {
                    dis[nextnode] = currtime+time;
                    pq.push({dis[nextnode],nextnode});
                }
            }
        }
        int ans = 1;
        for( int i=1;i<=n;i++){
            if(dis[i] == INT_MAX) return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
    }
};
