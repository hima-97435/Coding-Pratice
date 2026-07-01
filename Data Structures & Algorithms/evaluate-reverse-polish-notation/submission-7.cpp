class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto s: tokens){
            if(s != "+" && s != "-"&& s != "*" && s!= "/"){
                st.push(s);
            }
            else {
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                if(s == "+") st.push(to_string(x+y));
                else if(s == "-") st.push(to_string(y-x));
                else if(s == "*") st.push(to_string(x*y));
                else {
                    st.push(to_string(y/x));
                }
            }
        }
        return stoi(st.top());
    }
};
