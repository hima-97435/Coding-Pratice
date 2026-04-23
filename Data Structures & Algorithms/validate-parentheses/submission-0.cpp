class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> p = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (p.count(c)) {
                // it's a closing bracket
                if (!st.empty() && st.top() == p[c]) {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                // it's an opening bracket
                st.push(c);
            }
        }

        return st.empty();
    }
};
