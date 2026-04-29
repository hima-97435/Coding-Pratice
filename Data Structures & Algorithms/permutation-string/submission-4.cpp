class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // vector<int> need(26,0) , window(26,0);
        // int k = s1.size();
        // int n = s2.size();
        // for(char c: s1){
        //     need[c-'a']++;
        // }
        // for( int i=0;i<n;i++){
        //     window[s2[i]-'a']++;
        //     if(i>=k) window[s2[i-k]-'a']--;
        //     if(window == need) return true;
        // }
        // return false;
        vector<int> need(26,0), window(26,0);
        int k = s1.size();
        int n = s2.size();
        for(char c: s1) need[c-'a']++;
        for( int i=0;i<n;i++){
            window[s2[i]-'a']++;
            if(i>=k) window[s2[i-k]-'a']--;
            if(window == need) return true;
        }
        return false;
    }
};
