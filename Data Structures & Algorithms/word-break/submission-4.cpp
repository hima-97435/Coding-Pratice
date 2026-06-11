class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordlist ( wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0]= true;
        int maxlen = 0;
        for( const string &si: wordDict)
        {
            maxlen=max(maxlen, (int)si.size());
        }
        for( int i=1;i<=n;i++){
            for( int len=1;len<=maxlen && i-len>=0 ;len++){
                int j= i-len;
                if(dp[j]){
                    string suffix = s.substr(j,len);
                    if(wordlist.count(suffix)){
                        dp[i]= true;
                        break;
                    }
                }
            }
        }
        return dp[n];
    }
};
