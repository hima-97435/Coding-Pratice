class Solution {
public:

    string encode(vector<string>& strs) {
        string res="";
        for(auto st:  strs){
            res+=to_string(st.size())+'#'+st;
        }
        return res;
    }

    vector<string> decode(string s) {
        // int l =0;
        // int n = s.size();
        // vector<string> res;
        // while(l<n){
        //     int r = l;
        //     while(r<n && s[r] != '#') r++;
        //     int len = stoi(s.substr(l,r-l));
        //     string si = s.substr(r+1,len);
        //     res.push_back(si);
        //     l=r+l+1;
        // }
        // return res;
        vector<string> res;
        int i =0;
        int n = s.size();
        while(i<n){
            int j =i;
            while(j<n && s[j] != '#') j++;
            int l = stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1,l));
            i=j+1+l;
        }
        return res;
    }
};
