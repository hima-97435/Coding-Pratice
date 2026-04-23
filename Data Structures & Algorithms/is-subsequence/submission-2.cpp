class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        if( s == t) return true;
        else {
            int i =0, j =0;
            int n = s.size(), m = t.size();
            while(i<n && j < m){
                if(s[i] == t[j]) i++;
                j++;// check the string t.
            }
            if( i == n ) return true;
            else return false;
        }
    }
};