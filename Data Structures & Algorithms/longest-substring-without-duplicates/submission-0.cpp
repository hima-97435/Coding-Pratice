class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l =0, r=0;
        int n = s.size();
        int ans =0;
        unordered_set<char> set;
        while(r<n){
            while(set.count(s[r])){
                set.erase(s[l]);
                l++;
                
            }
            set.insert(s[r]);
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;

    }
};
