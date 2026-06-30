class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
     vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string, double>>> mp; 
        for(int i=0;i<equations.size();i++){
            string e1 = equations[i][0];
            string e2 = equations[i][1];
            double val = values[i];
            mp[e1].push_back({e2,val});
            mp[e2].push_back({e1,1/val});
        }   
        vector<double> res;
        for(const auto & q: queries){
            string s1 = q[0];
            string s2 = q[1];
            res.push_back(dfs(s1,s2,mp, unordered_set<string>()));
        }
        return res;
        
    }
    private:
    double dfs(const string& src, const string& target, 
        unordered_map<string , vector<pair<string,double>>> & adj ,
        unordered_set<string> visited){
            if(!adj.count(src) || !adj.count(target)) return -1.0;
            if(src == target) return 1.0;
            visited.insert(src);
            for(const auto & [nei, weight]: adj[src]){
                if(!visited.count(nei)) {
                    double res = dfs(nei,target,adj,visited);
                    if(res!= -1.0) return weight*res;
                }
            }
            return -1.0;
        }
};