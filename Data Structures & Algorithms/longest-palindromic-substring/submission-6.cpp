class Solution {
public:
    string longestPalindrome(string s) {
        string t;
        t+="^";
        for(char c :s) t+="#"+string(1,c);
        t+="#$";
        int n = t.size();
        vector<int> p(n, 0);
        int c =0, r=0;

        for(int i=1;i<n-1;i++){
            int imirror = 2*c-i; // [ imirror,,,, C ,,,, i] ==> d = i-c | c-imirror ==> imirror = 2*c-i
            if(r>i){
                p[i]= min(p[imirror], r-i);
            } 
            while(t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
            if(i+p[i] > r) {
                c =i;
                r = i+p[i];
            }

        }
        int start =0;
        int maxlen =0;
        for( int i=1;i<n;i++){
            if(p[i]> maxlen) {
                maxlen=p[i];
                start=i;
            }
        }
        int si = (start-maxlen-1)/2;
        return s.substr(si,maxlen);

    }
};
