class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, 
    vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string , vector<pair<string, double>>> adj;
        for( int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            adj[a].push_back({b, values[i]});
            adj[b].push_back({a,1.0/values[i]});

        }
        vector<double> res;
        for(const auto & q : queries){
            string src = q[0];
            string tar = q[1];
            res.push_back(dfs(src, tar, adj, unordered_set<string>()));

        }
        return res;
    }
private:
    double dfs( const string& src, const string& target ,
    unordered_map<string , vector<pair<string, double>>> adj,
    unordered_set<string> visited ){
        if(!adj.count(src) || !adj.count(target)) return -1.0;
        if(src == target) return 1.0;
        visited.insert(src);
        for(const auto &[ nei, weight] :  adj[src]) {
            if(!visited.count(nei)) {
                double res = dfs(nei, target, adj, visited);
                if(res != -1.0 ) return weight*res;
            }
        }
        return -1.0;
    }
};