class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto st : strs){
            res+=to_string(st.size())+'#'+st;
        }
        return res;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int l =0;
        vector<string> res;
        while(l<n){
             int r = l;
             while(r<n && s[r] != '#') r++;
             int len = stoi(s.substr(l, r-l));
             res.push_back(s.substr(r+1, len));
             l = r+1+len;
        }
        return res;
    }
};
