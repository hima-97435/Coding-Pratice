class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isword;
    TrieNode() : isword(false) {}
    void addword(const string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            if (!cur->children.count(c)){
                 cur->children[c] = new TrieNode();
                }
            cur = cur->children[c];
        }
        cur->isword = true;
    }
};

class Solution {
   public:
    unordered_set<string> res;
    vector<vector<bool>> visit;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            root->addword(word);
        }
        int rows = board.size(), col = board[0].size();
        visit.assign(rows, vector<bool>(col, false));
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < col; c++) {
                backtrack(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }
    void backtrack(vector<vector<char>>& board, int r, int c,TrieNode* node,  string word) {
        // if( i == word.size()) return true;
        // int ROWS= board.size(), COLS= board[]
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || visit[r][c] ||
            !node->children.count(board[r][c]))
            return;
        visit[r][c] = true;
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isword) res.insert(word);

        backtrack(board, r + 1, c, node, word);
        backtrack(board, r, c + 1, node, word);
        backtrack(board, r - 1, c, node, word);
        backtrack(board, r, c - 1, node, word);

        visit[r][c]= false;
    }
};
