class Solution {
public:
    int countSubstrings(string s) {
        string t;
        t+="^";
        for(char c: s) t+="#"+string(1,c);
        t+="#$";
        int n = t.size();
        vector<int> p(n,0);
        int c=0, r=0;
        for( int i=1;i<n-1;i++){
            int imirror = 2*c-i;
            if(r>i) p[i]=min(p[imirror],r-i);
            while(t[i+1+p[i]] == t[i-1-p[i]]) p[i]++;
            if(i+p[i] > r) {c=i; r=1+p[i];}
        }
        int count =0;
        for( int x: p){
            count+=(x+1)/2;
        }
        return count;

    }
};
