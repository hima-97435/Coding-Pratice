class Solution {
    vector<vector<int>> adj;
    unordered_map<int, unordered_set<int>> mp;

public:
    vector<bool> checkIfPrerequisite(int numCourses, 
    vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    adj.assign(numCourses, vector<int> ());
    for(auto & p : prerequisites){
        adj[p[1]].push_back(p[0]);
    }
    for( int i=0;i<numCourses;i++){
        dfs(i);
    }
    vector<bool> res;
    for(auto & q : queries){
        res.push_back(mp[q[1]].count(q[0]));
    }
    return res;
    }
private:
    unordered_set<int>& dfs(int xr){
        if(mp.count(xr)) return mp[xr];
        mp[xr]=unordered_set<int>();
        for( int p : adj[xr]) {
            auto &xur = dfs(p);
            mp[xr].insert(xur.begin(),xur.end());

        }
        mp[xr].insert(xr);
        return mp[xr];
    }
};