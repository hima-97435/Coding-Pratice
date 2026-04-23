class Solution {
   private:
    int id_palindrome(string s, int l, int r){
// to basically calulate all things right .
// we will be given string and index of l and right .
// and jitna possible ho sakhta voh return kar dega.
int value=0;
int n = s.size();

        while( l>=0 && r<n && s[l] == s[r]){
            value++;
            l--;
            r++;

        }
        return value;
    }
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res=0;
    // itertae over every charcter right like a b c ...
    for( int i=0;i<n;i++){
        res+=id_palindrome(s,i,i);
        res+=id_palindrome(s,i,i+1);

    }
    return res;

    }
};
