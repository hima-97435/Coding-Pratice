class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>> mp;
        for(const string&s : strs){
            // string key = s;
            vector<int> count(26,0);
            for(char c: s){
                count[c-'a']++;
            }
            string key = to_string(count[0]);
            for( int i=1;i<26;i++){
                key+=','+to_string(count[i]);
            }
            // sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto & x: mp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
