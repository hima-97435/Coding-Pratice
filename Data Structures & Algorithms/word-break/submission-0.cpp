class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n,false);
        dp[n]=true;
        for( int i=n-1;i>=0;i--){
            for( const auto& w :wordDict){
                if((i+w.size()<=n && s.substr(i,w.size()) == w)){
                    dp[i]=dp[i+w.size()];
                }
                if(dp[i]) break;
            }
            // tackle 2 thing how to handle how to check 
            // whether string is there in word dictionary or not
        }
        return dp[0];
    }
};
