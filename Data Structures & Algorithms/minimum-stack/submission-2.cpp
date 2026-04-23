class MinStack {
    stack<pair<int,int>> st;
    // stack<int> minst;
 
// ÷ 
    // }
    public: 
    void push(int val) {
        int cur_min=st.empty() ?val:min(val,st.top().second);
        st.push({val,cur_min});
          }
    
    void pop() {
        // if(st.top() == minst.top()) minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top().first;

    }
    
    int getMin() {
        return st.top().second;
    }
};
