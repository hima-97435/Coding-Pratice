class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, 
    int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for(int i=0;i<edges.size();i++) {
            int src = edges[i][0], dst=edges[i][1];
            adj[src].push_back({dst,succProb[i]});
            adj[dst].push_back({src,succProb[i]});
        }
        vector<double> maxprob(n, 0.0);
        maxprob[start_node]=1.0;
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        while(!pq.empty()){
            auto[curr_prob, node]= pq.top();
            pq.pop();
            if(node == end_node) return curr_prob;
            if(curr_prob<maxprob[node]) continue;
            for(auto&[nei, edge_prob]: adj[node]) {
                double new_prob = curr_prob*edge_prob;
                if(new_prob>maxprob[nei]) {maxprob[nei]=new_prob; pq.push({new_prob,nei});}
            }
        }
        return 0.0;
    }
};