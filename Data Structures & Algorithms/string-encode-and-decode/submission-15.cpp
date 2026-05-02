class Solution {
public:
// final encoded string would be like 
// #5hello#5world --> wrong
// 5#hello5#world --> correct
    string encode(vector<string>& strs) {
        string si = "";
        for(string s : strs){
            si+=to_string(s.size()) +"#"+s;
        }
        return si;

    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j]!='#') j++;
            int len = stoi(s.substr(i,j-i));
            i=j+1;
            ans.push_back(s.substr(i,len));
            i+=len;
        }
        return ans;
    }
};
