class Solution {
public:
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0' ) return 0;
        int n = s.size();
        int oneback = 1;
        int twoback = 1;
        for( int i=1;i<n;i++){
            int current =0 ;
            if(s[i]!= '0') current+=oneback;
            string two= s.substr(i-1,2);
            if(two>="10" && two<="26") current+=twoback;
            if(current == 0) return 0;
            twoback=oneback;
            oneback = current;
        }
        return oneback;
    }
};
