class Solution {
public:

    string encode(vector<string>& strs) {
        string s ;
        for( const string st : strs){
            int len = st.size();
            s+=to_string(len)+"!"+st;
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int n = s.size();
        int i=0;
        while(i<n){
            int j =i;
            while(s[j]!='!'){
                j++;
            }
            int len = stoi(s.substr(i, j-i));
            i = j+1;
            j=i+len;
            res.push_back(s.substr(i, len));
            i=j;
        }
        return res;
    }
};
