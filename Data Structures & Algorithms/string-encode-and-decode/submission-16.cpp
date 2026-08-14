class Solution {
public:
    // len(string)#string
    string encode(vector<string>& strs) {
        string ans="";
        for(auto t: strs){
            int len = t.size();
            ans+=to_string(len)+"#"+t;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int n = s.size();
        for(int i=0;i<n;i++){
            int j = i; 
            while(j<n and s[j] != '#') j++;
            int len = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1,len));
            i=j+len;
        }
        return ans;
    }
};
