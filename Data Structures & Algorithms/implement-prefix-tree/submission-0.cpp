class trie{
    public: 
    unordered_map<char, trie*> children;
    bool endofword = false;
};
class PrefixTree {
    trie* root;
public:
    PrefixTree() {
        root= new trie();
    }
    
    void insert(string word) {
        trie* cur = root;
        for(char c: word){
            if(cur->children.find(c) == cur->children.end()) cur->children[c]=new trie();
            cur=cur->children[c];
        }
        cur->endofword=true;
    }
    
    bool search(string word) {
        trie* cur = root;
        for(char c: word){
            if(cur->children.find(c) == cur->children.end()) return false;
            cur=cur->children[c];
        }
        return cur->endofword;
    }
    
    bool startsWith(string prefix) {
        trie* cur = root;
        for(char c: prefix){
            if(cur->children.find(c) == cur->children.end()) return false;
            cur=cur->children[c];
        }
        return true;
    }
};
