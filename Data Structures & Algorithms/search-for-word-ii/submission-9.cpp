struct TrieNode{
    unordered_map<char, TrieNode*> children;
    bool isword;
    TrieNode(){
        isword=false;
    }
    void addword(string s){
        TrieNode* cur = this;
        for(char c: s){
            if(!cur->children.count(c)) cur->children[c]= new TrieNode();
            cur=cur->children[c];
        }
        cur->isword=true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size() , n = board[0].size();
        TrieNode * cur = new TrieNode();
        for(auto t: words) cur->addword(t);
        unordered_set<string> st;
        vector<vector<bool>> visit(m , vector<bool>(n, false));
        auto dfs = [&] (auto &&self, int i , int j , TrieNode* cur, string word)-> void{
            if(i<0 or j<0 or i>= m or j>= n or visit[i][j] or !cur->children.count(board[i][j])) return ;
            visit[i][j]=true;
            cur=cur->children[board[i][j]];
            word+=board[i][j];
            if(cur->isword) st.insert(word);
            self(self,i+1,j,cur,word);
            self(self,i-1,j,cur,word);
            self(self,i,j+1,cur,word);
            self(self,i,j-1,cur,word);
            visit[i][j]=false;
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dfs(dfs,i,j,cur,"");
            }
        }
        return vector<string>(st.begin(),st.end());
    }
};
