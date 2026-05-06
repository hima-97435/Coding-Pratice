class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // [1,3,7]
        // if considering 1 as all same throught height then area becomes 1X3 = 3
        // for considering 3 for index 1 and 2 then area becomes 3X2= 6 
        // ouptut is 7 how?
        // picked last element
        // [7,1,7,2,2,4]
        // pick last 4 elements and there minimum then the output would 4X2 = 8 coorect output
       int n = heights.size();
       stack<int> st;
       int maxarea=0;
       for( int i=0;i<=n;i++){
        int currheight= (i == n) ?0:heights[i];
        while(!st.empty() && currheight < heights[st.top()]){
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i: (i-st.top()-1);
            maxarea=max(maxarea,h*w);
        }
        st.push(i);
       }
       return maxarea;
    }
};
