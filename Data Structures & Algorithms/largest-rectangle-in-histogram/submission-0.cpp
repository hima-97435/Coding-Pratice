class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int , int>> st;
        int maxarea=0;
        for( int i=0;i<n ;i++){
            int index = i;
            while(!st.empty() && st.top().second > heights[i]){
                auto t = st.top();
                st.pop();
                maxarea=max(maxarea, (i-t.first)*(t.second));
                index = t.first;
            }
            st.push({index,heights[i]});
        }
        while(!st.empty()){
             auto t = st.top();
                st.pop();
                maxarea=max(maxarea, (n-t.first)*(t.second));
            
        }
        return maxarea;
    }
};
