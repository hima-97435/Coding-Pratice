class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> st1(temp.size(),0);
        stack<pair<int, int>> st;
        for( int i= 0;i<temp.size();i++){
            while(!st.empty() && st.top().first< temp[i]) {
                // st.push({temp[i],temp[i]});
                auto pair = st.top();
                st.pop();
                st1[pair.second] = i -pair.second;
                
                // st1.push_back(i);
            }
            st.push({temp[i],i});
        }
        return st1;
    }
};
