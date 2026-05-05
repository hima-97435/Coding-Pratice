class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string c : tokens){
            if(c != "+" && c != "-" && c!= "*" && c!= "/"){
                // digits will come
                st.push(stoi(c));
            }
            else {
                int t1= st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                if(c == "+") {
                    st.push(t1+t2);
                }
                else if(c == "-") {
                    st.push(t2-t1);
                }
                else if(c == "*"){
                    st.push(t1*t2);
                }
                else {
                    st.push(t2/t1);
                }

            }
        }
        return st.top();
    }
};
