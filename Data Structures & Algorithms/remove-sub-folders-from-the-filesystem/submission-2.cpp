class Trie {
public:
    Trie* children[128] = {};
    bool end_of_folder = false;

    void add(const string& path) {
        Trie* cur = this;
        string part;
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '/') {
                if (!part.empty()) {
                    for (char c : part) {
                        if (!cur->children[(int)c]) cur->children[(int)c] = new Trie();
                        cur = cur->children[(int)c];
                    }
                    if (!cur->children[(int)'/']) cur->children[(int)'/'] = new Trie();
                    cur = cur->children[(int)'/'];
                    part.clear();
                }
            } else {
                part += path[i];
            }
        }
        if (!part.empty()) {
            for (char c : part) {
                if (!cur->children[(int)c]) cur->children[(int)c] = new Trie();
                cur = cur->children[(int)c];
            }
            if (!cur->children[(int)'/']) cur->children[(int)'/'] = new Trie();
            cur = cur->children[(int)'/'];
        }
        cur->end_of_folder = true;
    }

    bool prefixSearch(const string& path) {
        Trie* cur = this;
        string part;
        for (int i = 0; i < (int)path.size(); i++) {
            if (path[i] == '/') {
                if (!part.empty()) {
                    for (char c : part) cur = cur->children[(int)c];
                    cur = cur->children[(int)'/'];
                    if (cur->end_of_folder) return true;
                    part.clear();
                }
            } else {
                part += path[i];
            }
        }
        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie trie;
        for (auto& f : folder) trie.add(f);
        vector<string> res;
        for (auto& f : folder) {
            if (!trie.prefixSearch(f)) res.push_back(f);
        }
        return res;
    }
};