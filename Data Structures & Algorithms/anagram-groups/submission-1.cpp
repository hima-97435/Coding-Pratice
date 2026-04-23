class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       unordered_map<string , vector<string> > m11;
       for(string s: strs){
        string k=s;
        sort(k.begin(),k.end());
        m11[k].push_back(s);
       } 
       vector<vector<string>> result;
       for(auto &p : m11){
        result.push_back((p.second));
       }
       return result;
    }
};
