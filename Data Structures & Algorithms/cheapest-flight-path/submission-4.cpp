class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int , int>>> adj(n);
        for(auto& i: flights){
            adj[i[0]].push_back({i[1],i[2]});

        }
        vector<int> vis(n , INT_MAX);
        priority_queue<tuple<int , int, int> , vector<tuple<int , int, int> >, greater<tuple<int , int, int>> > pq;
        pq.push({0,src,-1});
        vis[src]=0;
        while(!pq.empty()){
            auto [price, node, stops_used] = pq.top();
            pq.pop();
            if(node == dst) return price;
            if(stops_used == k) continue;
            for(auto &ni : adj[node]){
                int nextnode = ni.first;
                int flightprice= ni.second;
                // int stop = k+1-(stops_used);
                if(price+ flightprice < vis[nextnode]) {
                    vis[nextnode]= price+flightprice;
                    pq.push({price+flightprice, nextnode,stops_used+1});
                }
                else if(stops_used+1<=k) {
                     pq.push({price+flightprice, nextnode,stops_used+1});
                }
            }
        }
        return -1;
    }
};
