class Solution {
public:
    string minWindow(string s, string t) {
        // if(t.size()> s.size()) return "";
        // vector<int> need(128,0);
        // for(char c: t) need[c]++;
        // int n = s.size();
        // int minlen = n+1;
        // int required = t.size();
        // int start =0;
        // int l =0;
        // for( int r=0;r<n;r++){
        //     if(need[s[r]] > 0 ) required--;
        //     need[s[r]]--;
        //     while(required == 0){
        //          int len = r-l+1;
        //          if(len<minlen){
        //             minlen=len;
        //             start=l;
        //          }
        //          need[s[l]]++;
        //          if(need[s[l]] > 0 ) required++;
        //          l++;
        //     }
        // }
        // return (minlen == n+1) ? "" : s.substr(start,minlen);
        if(t.size()>s.size()) return "";
        vector<int> need(128,0);
        for(char c: t) need[c]++;
        int n = s.size() , minlen=n+1, required=t.size() , start=0, l=0;
        for( int r =0;r<n;r++){
            if(need[s[r]] > 0) required--;
            need[s[r]]--;
            while(required == 0 ){
                int len = r-l+1;
                if(len<minlen) {
                minlen=len;
                start=l;
                }
                need[s[l]]++;
                if(need[s[l]]> 0 )required++;
                l++;
            }
        }
        if( minlen == n+1) return "";
        else return s.substr(start,minlen);

    }
};
