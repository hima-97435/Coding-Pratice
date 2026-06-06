class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string> , greater<string>>> adj;
    vector<string> ans;
    void dfs(string res){
        while(!adj[res].empty()){
            string nextword = adj[res].top();
            adj[res].pop();
            dfs(nextword);
        }
        ans.push_back(res);

    } 
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto & t: tickets){
            adj[t[0]].push(t[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
