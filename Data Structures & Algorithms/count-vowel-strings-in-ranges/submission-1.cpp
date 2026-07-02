class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_set<char> st= {'a','e','i','o','u'};
        vector<int> ans;
        for(auto q : queries){
            int l = q[0];
            int r = q[1];
            int cnt =0;
            for(int i=l;i<=r;i++){
                string word = words[i];
                if((st.find(word[0]) != st.end()) && (st.find(word[word.size()-1]) != st.end())) cnt++;
              
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};