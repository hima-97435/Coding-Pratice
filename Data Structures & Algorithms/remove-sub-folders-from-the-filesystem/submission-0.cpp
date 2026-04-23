class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        unordered_set<string> folderr(folder.begin(), folder.end());
        for(string & f : folder){
            res.push_back(f);
            for( int i=0;i<f.size();i++){
                if(f[i] == '/' && folderr.count(f.substr(0,i))) {
                    res.pop_back();
                    break;
                }
            }
        }
        return res;
    }
};