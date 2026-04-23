class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        unordered_map<char , char> p={
             {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for(char c: s) {
            if(p.count(c)){
                if(!st.empty() && st.top() == p[c]) st.pop();
                else return false;
            }
            else st.push(c);
        }
        return st.empty();
    }
};
