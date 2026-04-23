class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int ans =0;
       for( int i=0;i<s.length();i++){
       unordered_map<char, int> mp;
       int maxf=0;
        for(int j=i;j<s.size();j++){
            mp[s[j]]++;
            maxf= max(maxf,mp[s[j]]);
            if((j-i+1)-maxf <=k) {
                ans=max(ans,j-i+1);
            }
        }
        
       }
       return ans;
    }
};
