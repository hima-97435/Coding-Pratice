class Solution {
public:
    string longestPalindrome(string s) {
        string t="#"+string(1,s[0]);
        for(int i=1;i<s.size();i++) t+="#"+string(1,s[i]);
        t+="#";
        int n = t.size();
        vector<int> p(n,0);

        int l=0,r=0;
        for(int i=0;i<n;i++){
            p[i]= (i<r)?min(r-i,p[l+(r-i)]):0;
            while(i+p[i]+1<n and i-p[i]-1>=0  and t[i+p[i]+1] == t[i-p[i]-1]) p[i]++;
            if(i+p[i]>r) {l=i-p[i]; r=i+p[i];}
        }
        int reslen=0, center_index=0;
        for(int i=0;i<n;i++){
            if(p[i]>reslen) {reslen=p[i]; center_index=i;}
        }
        int resindex=(center_index-reslen)/2;
        return s.substr(resindex,reslen);
       
    }
};
