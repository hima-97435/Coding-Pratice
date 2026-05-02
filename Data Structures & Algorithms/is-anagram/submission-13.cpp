class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        int n1 = s.size();
        int n2 = t.size();
        if(n1 != n2) return false; 
        int i=0;
        while(i<(min(n1,n2)) && s[i] == t[i]) i++;
        
        return i == min(n1,n2);
    }
};
