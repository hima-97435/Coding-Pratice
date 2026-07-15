class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0;
        unordered_set<char> st;
        int maxlen= 0;
        for(int r =0;r<s.size();r++){
            while(st.find(s[r]) != st.end()) {
                // character is there
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxlen= max(maxlen,r-l+1);
        }
        return maxlen;
    }
};
