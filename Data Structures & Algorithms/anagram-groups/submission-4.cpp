class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      // can use vector 26 size to store unique string -->
      // treat this as key and value would be that string 
      // and then at the end push them based on key 
      // for storing can use map

      // not coorect 
        unordered_map<string, vector<string>> mp;
        for(const auto& st : strs){
            vector<int> count(26,0);
            for(char c : st){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for( int i=1;i<26;i++){
                key+=','+to_string(count[i]);
            }
            mp[key].push_back(st);
        }
        vector<vector<string>> ans;
        for(auto & pair: mp){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
