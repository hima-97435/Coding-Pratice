class MinStack {
    stack<pair<int , int>> st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int curr_min = st.empty() ?  val :  min(st.top().second, val);
        st.push({val, curr_min});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
       return st.top().second;
    }
};
