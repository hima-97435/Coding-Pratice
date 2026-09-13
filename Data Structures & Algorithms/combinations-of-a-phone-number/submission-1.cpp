class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        unordered_map<char , string> phonemap = {
        {'2',"abc"},
        {'3',"def"},
         {'4',"ghi"},
         {'5',"jkl"},
         {'6',"mno"},
         {'7',"pqrs"},
         {'8',"tuv"},
         {'9',"wxyz"}
    };
    auto backtrack = [&](auto&&self, int index)->void{
        if(index == digits.size()) {
            ans.push_back(cur);
            return;
        }
        char dg = digits[index];
        string s = phonemap[dg];
        for(char c: s){
            cur.push_back(c);
            self(self,index+1);
            cur.pop_back();
        }
    };
    if(digits.empty()) return ans;
    backtrack(backtrack,0);
    return ans;
       

    }
};
