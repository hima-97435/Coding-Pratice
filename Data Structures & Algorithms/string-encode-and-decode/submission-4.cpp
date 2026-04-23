class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto& s : strs) {
            res+=to_string(s.size())+'#'+s;

        }
        return res; 
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i<s.size()){
            int j=i;
            while(s[j] != '#') j++;
            int l = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,l));
            i=j+l+1;
        }
        return ans;
    }
};
