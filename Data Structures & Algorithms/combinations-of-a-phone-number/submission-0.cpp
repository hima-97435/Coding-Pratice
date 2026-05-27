class Solution {
public:
    unordered_map<int , string> phonemap = {
        {'2',"abc"},
        {'3',"def"},
         {'4',"ghi"},
         {'5',"jkl"},
         {'6',"mno"},
         {'7',"pqrs"},
         {'8',"tuv"},
         {'9',"wxyz"}
    };
    void backtrack(string &digits, int index, string& currentstr, vector<string>& result){
        if( index == digits.size()) {
            result.push_back(currentstr);
            return;
        }
        char character= digits[index];
        string letter= phonemap[character];
        for(char c: letter){
            currentstr.push_back(c);
            backtrack(digits, index+1,currentstr, result);
            currentstr.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()) return result;
        string currentstr="";
        backtrack(digits,0, currentstr,result);
        return result;
    }
};
