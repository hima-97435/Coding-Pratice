class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> prefix(words.size()+1,0);
        unordered_set<char> st = {'a','e','i','o','u'};
        for(int i=0;i<words.size();i++){
            prefix[i+1]= prefix[i];
            if(st.count(words[i][0]) && st.count(words[i].back())) prefix[i+1]++;
        }
        vector<int> res;
        for(auto &q: queries){
            int l = q[0];
            int r = q[1];
            res.push_back(prefix[r+1]-prefix[l]);
        }
        return res;
    }
};