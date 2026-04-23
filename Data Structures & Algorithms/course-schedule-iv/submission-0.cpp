class Solution {
    vector<vector<int>> adj;

public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    adj.assign(numCourses, vector<int> ());
    for(auto & p : prerequisites ){
        adj[p[0]].push_back(p[1]);
    }    
    vector<bool> res;
    for(auto & q: queries){
        res.push_back(dfs(q[0],q[1]));
    }
    return res;
    }
private:
    bool dfs(int node , int target){
        if(node == target) return true;
        for( int n : adj[node]){
            if(dfs(n, target)) return true;
        }
        return false;
    }
};