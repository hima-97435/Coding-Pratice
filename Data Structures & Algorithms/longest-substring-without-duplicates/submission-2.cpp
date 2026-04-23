class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_set<char> at;
        int l =0;
        int r =0;
        int ans =0;
        while(r<n){
            while(at.count(s[r]) ) {
                at.erase(s[l]);
                l++;
            }
            at.insert(s[r]);
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
