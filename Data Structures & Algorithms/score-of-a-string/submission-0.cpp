class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size();
        int sum =0;
        for(int i=0;i<n-1;i++){
            int cur = (int)s[i];
            int nxt = (int)s[i+1];
            sum+=abs(nxt-cur);
        }   
        return sum;
    }
};