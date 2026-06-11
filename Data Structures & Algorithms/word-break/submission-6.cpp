struct trienode{
    trienode* children[26]= {nullptr};
    bool endofword=false;

};
class Solution {
public:
    void insert(const string & word, trienode* root){
        trienode* cur= root;
        for(char c:  word){
            if(!cur->children[c-'A' && c<='Z'? c-'A' : c-'a']){
                cur->children[c-'a']= new trienode();
            }
            cur=cur->children[c-'a'];

        }
        cur->endofword=true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        trienode* root = new trienode();
        for(const string &word: wordDict){
            insert(word,root);
        }
        int n = s.size();
        vector<int> dp(n+1, false);
        dp[0]= true;
        for( int i=0;i<n;i++){
            if(!dp[i]) continue;
            trienode* curr = root;
            for( int j=i;j<n;j++){
                char c = s[j];
                if(!curr->children[c-'a']) break;
                curr= curr->children[c-'a'];
                if(curr->endofword ) dp[j+1]= true;
            }
        }
        return dp[n];
    }
};
