class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(const string&t : tokens){
            if(!( t == "+" || t == "-" || t == "*" || t == "/")) st.push(t);
            else {
                int t1= stoi(st.top());
                st.pop();
                int t2= stoi(st.top());
                st.pop();
                if(t == "+") st.push(to_string(t1+t2));
                else if(t == "-") st.push(to_string(t2-t1));
                else if(t == "*") st.push(to_string(t1*t2));
                else st.push(to_string(t2/t1));
            }
        }
        return stoi(st.top());
    }
};
