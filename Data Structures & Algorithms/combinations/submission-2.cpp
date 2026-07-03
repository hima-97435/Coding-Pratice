class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        auto dfs = [&] (auto && self, int start) -> void{
            if(combination.size() == k) {
                res.push_back(combination);
                return;
            }
            for(int i=start;i<=n;i++){
                combination.push_back(i);
                self(self,i+1);
                combination.pop_back();
            }
        };
        dfs(dfs,1);
        return res;
    }
    void backtrack(int i , int n , int k , vector<int> & combination){
        if(i>n) {
            if(combination.size() == k) res.push_back(combination);
            return;
        }
        combination.push_back(i);
        backtrack(i+1,n , k, combination);
        combination.pop_back();
        backtrack(i+1,n,k,combination);
    }
};