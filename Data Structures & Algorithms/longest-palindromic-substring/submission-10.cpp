class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len =1;
        string ans;
        ans+=s[0];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int l =i, r = j;
                while(l<r&&s[l] == s[r]) {l++; r--;}
                if(l>=r && len<(j-i+1)){
                    ans=s.substr(i,j-i+1);
                    len=j-i+1;
                }
            }
        }
        return ans;
    }
};
