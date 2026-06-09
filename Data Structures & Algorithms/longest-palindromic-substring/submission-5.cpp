class Solution {
public:
    int expandee(string s, int l , int r){
        while(l>=0 && r<s.size() && s[l] == s[r]) {l--; r++;}
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return"";
        int start =0;
        int maxlen =0;
        int n = s.size();
        for( int i=0;i<n;i++){
            int len1 = expandee(s, i , i);
            int len2 = expandee(s, i , i+1);
            int curlen= max(len1, len2);
            if(curlen>maxlen) {
                maxlen= curlen;
                start=i-(curlen-1)/2;
            }
        }
        return s.substr(start, maxlen);
    }
};
