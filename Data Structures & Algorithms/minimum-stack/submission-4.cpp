class MinStack {
   public:
   vector<pair<int , int>> st;
    MinStack() {}

    void push(int val) {
        if(st.empty()) st.push_back({val , val});
        else {
            int curmin= min(val , st.back().second);
            st.push_back({val,curmin});
        }
    }

    void pop() {
        if(!st.empty()) st.pop_back();
    }

    int top() {
        return st.back().first;
    }

    int getMin() {
        return st.back().second;
    }
};
