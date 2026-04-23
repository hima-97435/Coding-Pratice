class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        string ans="";
        int reslen=0;
        for(int i=0;i<n;i++ ){
            for( int j =i;j<n;j++){
                int l = i;
                int r=j;
                while(l<r && s[l]==s[r]) {
                    l++;
                    r--;

                }
                if(l>=r && reslen<(j-i+1)){
                    ans=s.substr(i,j-i+1);
                    reslen=j-i+1;
                }
            }
        }
        return ans;
    }
    
};
