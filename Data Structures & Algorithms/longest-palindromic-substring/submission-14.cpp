class Solution {
public:
    string longestPalindrome(string s) {
        string res ="";
        int reslen =0;
        for(int i=0;i<s.size();i++){
            // odd length 
            int l = i,  r =i;
            while( l>=0 and r<s.size() and s[l] == s[r]) {
                if((r-l+1) > reslen){
                    reslen = r-l+1;
                    res=s.substr(l, reslen);
                }
                l--;
                r++;
            }
            // even length
            l = i, r = i+1;
            while( l>=0 and r<s.size() and s[l] == s[r]) {
                if((r-l+1) > reslen){
                    reslen = r-l+1;
                    res=s.substr(l, reslen);
                }
                l--;
                r++;

            }
        }
        return res;
    }
};
