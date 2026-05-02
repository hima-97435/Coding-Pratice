class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> map;
        for(const string &s :  strs){
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }
            string k = to_string(count[0]);
            for(int i=1;i<26;i++){
                k+=','+to_string(count[i]);
            }
            map[k].push_back(s);
        }
        vector<vector<string>> ans;
        for(const auto& [key, value] : map){
            ans.push_back(value);
        }
        return ans;
    }
};
