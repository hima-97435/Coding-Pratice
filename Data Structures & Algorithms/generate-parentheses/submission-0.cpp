class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr = "";
        dfs(n , 0 , 0 , curr, res);
        return res;
    }
    void dfs(int n , int open , int close, string& curr, vector<string>& res){
        if(curr.size() == 2*n) {
            res.push_back(curr);
            return;
        }
        if(open<n){
            curr.push_back('(');
            dfs(n, open+1, close, curr, res);
            curr.pop_back();

        }
        if(close<open){
            curr.push_back(')');
            dfs(n ,open, close+1, curr, res);
            curr.pop_back();
        }
    }
};
