class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> st;
        int n = s.size(), l =0 ;
        int ans =1;
        for( int r=0;r<n;r++){
            while(st.count(s[r])) {
                // ans = max(ans, r-l+1);
                st.erase(s[l]);
                l++;
            }
           
                st.insert(s[r]);
                ans = max(ans, r-l+1);


        }
        return ans;
    }
};
