class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>> memo(s.size()+1, vector<int>(p.size()+1, -1));
        return dfs(0,0,s,p,memo);
    }
    bool dfs(int i , int j , string s , string p, vector<vector<int>>& memo){
        if(memo[i][j] != -1) return memo[i][j];
        if(j == p.size() ) return memo[i][j] = (i == s.size());
        bool current = (i<s.size() && (s[i] == p[j]|| p[j] == '.'));
        if(j+1<p.size() && p[j+1] == '*'){
            bool shrink = dfs(i,j+2,s,p,memo);
            bool stretch = current&&dfs(i+1,j,s,p,memo);
            return memo[i][j]=(shrink||stretch);

        }
        return memo[i][j]=(current&&dfs(i+1,j+1,s,p,memo));
    }
};
// aa *b
// *--> kuch bhi laga lo
