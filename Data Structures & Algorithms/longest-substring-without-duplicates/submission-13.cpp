class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> st;
        int l =0, res =0;
        for(int i=0;i<s.size();i++){
            while(st.count(s[i])) {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[i]);
            res=max(res,i-l+1);
        }
        return res;
    }
};
