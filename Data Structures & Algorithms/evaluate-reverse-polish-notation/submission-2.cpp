class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int sum =0;
        for(auto &p : tokens){
            if(p != "+" && p != "-" && p != "*" && p != "/") {
                st.push(stoi(p));
            }
            else {
                int b = st.top(); st.pop();  // second operand
                int a = st.top(); st.pop();  // first operand

                if (p == "+") st.push(a + b);
                else if (p == "-") st.push(a - b);
                else if (p == "*") st.push(a * b);
                else if (p == "/") st.push(a / b);  //
            }
        }
        return st.top();
    }
};
