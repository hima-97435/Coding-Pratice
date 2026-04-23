class Solution {
    vector<string>* globalPtr;

void foo(vector<string>& arr) {
    globalPtr = &arr;  // store address
}

public:

    string encode(vector<string>& strs) {
       string res;
       for(auto& s : strs){
        res+=to_string(s.size()) +'#' +s;

       }
       return res;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j =i;
            while(s[j] !='#') j++;
            int l = stoi(s.substr(i,j-i));
            ans.push_back(s.substr(j+1, l));
            i=j+1+l;

        }
        return ans;
    }
};
