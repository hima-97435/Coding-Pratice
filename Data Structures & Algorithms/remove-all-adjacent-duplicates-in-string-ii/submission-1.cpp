class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<int> st;
        int n = s.length();
        int i=0;
        while(i<n){
            if( i == 0 || s[i] != s[i-1]) st.push_back(1);
            else {
                st.back()++;
                if(st.back() == k) {
                    st.pop_back();
                    s.erase(i-k+1,k);
                    i-=k;
                    n-=k;
                }
            }
            i++;
        }
        return s;
    }
};