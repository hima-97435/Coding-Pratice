class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char,unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for(string &word: words ){
            for(char c: word){
                indegree[c] =0;
            }
        }
        for( int i=0;i<words.size()-1;i++){
            string w1 = words[i];
            string w2 = words[i+1];

            if(w1.length()> w2.length() && w1.substr(0,w2.size()) == w2) return "";
            int minlen= min(w1.size(), w2.size());
            for( int j=0;j<minlen;j++){
                if(w1[j] != w2[j]) {
                    char parent = w1[j];
                    char child = w2[j];
                    if(adj[parent].find(child) == adj[parent].end()) {
                        adj[parent].insert(child);
                        indegree[child]++;
                        
                    }
                    break;
                }
            }
        }
        queue<char> q;
        for( auto & p : indegree){
            if(p.second == 0) q.push(p.first);
        }
        string result = "";
        while(!q.empty()){
            char ele = q.front();
            q.pop();
            result+=ele;
            for(char ne : adj[ele]){
                // char nextele =n;
                indegree[ne]--;
                if(indegree[ne] == 0) q.push(ne);
            } 
        }
        if(result.size()< indegree.size()) return "";
    return result;
    }
};
