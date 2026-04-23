class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string , vector<string> > m11;
       for(const auto& s :strs){
        vector<int> count(26,0);
        for(char c: s){
            count[c-'a']++;
        }
        string k =to_string(count[0]);
        for(int i=1;i<26;i++){
            k+=','+to_string(count[i]);
        }
        m11[k].push_back(s);
       }
       vector<vector<string>> res;
       for(const auto &pair: m11){
            res.push_back(pair.second);
       }
       return res;
    }
};
