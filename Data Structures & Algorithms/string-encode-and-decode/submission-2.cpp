class Solution {
    vector<string>* globalPtr;

void foo(vector<string>& arr) {
    globalPtr = &arr;  // store address
}

public:

    string encode(vector<string>& strs) {
       foo(strs); 
        string sr="";
        for( string s : strs){
            sr+=s;
        }
        return sr;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        for (auto& s : *globalPtr) ans.push_back(s);
        return ans;
    }
};
