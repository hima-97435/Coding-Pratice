struct trienode{
    
    trienode* children[26]={nullptr};
    bool isword = false;
};
class Solution {
public:
    void insert(trienode* root, const string& word){
        trienode* curr = root;
        for(char c:  word){
            if(!curr->children[c-'A' && c<='Z'?c-'A':c-'a']){
                curr->children[c-'a'] = new trienode();

            }
            curr=curr->children[c-'a'];
        }
        curr->isword= true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        trienode * root= new trienode();
        for(const string & word: wordDict){
            insert(root, word);
        }
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0]= true;
        for( int i=0;i<n;i++){
            if(!dp[i]) continue;
            trienode* curr = root;
            for( int j=i;j<n;j++){
                char c = s[j];
                if(!curr->children[c-'a'])  break;
                curr= curr->children[c-'a'];
                if(curr->isword) dp[j+1] = true;
            }
        }
        return dp[n];
    }
};
