class trienode{
    public:
    unordered_map<char, trienode*> children;
    bool isword;
    trienode(): isword(false) {}
    void addword(const string& w){
        trienode* cur = this;
        for(char c: w){
            if(!cur->children.count(c)) cur->children[c]=new trienode();
            cur=cur->children[c];
        }
        cur->isword=true;
    }
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size() , n = board[0].size();
        trienode* root = new trienode();
        for(auto w: words){
            root->addword(w);
        }
        unordered_set<string> res;
        vector<vector<bool>> visit(m, vector<bool>(n,false));
        auto backtrack = [&](auto&&self, int r, int c, trienode* node , string word) -> void{
            if(r<0 or c<0 or r>= m or c>=n or visit[r][c] or !node->children.count(board[r][c])) return;
            visit[r][c]= true;
            node=node->children[board[r][c]];
            word+=board[r][c];
            if(node->isword) res.insert(word);
            self(self,r+1,c,node,word);
            self(self,r-1,c,node, word);
            self(self,r,c+1,node, word);
            self(self,r,c-1,node,word);
            visit[r][c]= false;
        };
        for(int r=0;r<m ;r++){
            for(int c=0;c<n;c++){
                backtrack(backtrack, r, c, root,  "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};
