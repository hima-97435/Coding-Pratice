class Solution {
public:
    bool isPalindrome(string s) {
        string s_n="";
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (isalnum(c)) {
                s_n += tolower(c);
            }
        }
        int l =0,r = s_n.size()-1;
        while(l<r) {
            if(s_n[l] != s_n[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
