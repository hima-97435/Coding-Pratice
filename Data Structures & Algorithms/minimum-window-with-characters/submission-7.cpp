class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char c : t) mp[c]++;
        int have =0, need = mp.size();
        unordered_map<char, int> window;
        int l=0,r=0, reslen=INT_MAX;
        pair<int, int> res= {-1,-1};
        for(r=0;r<s.size();r++){
            char c = s[r];
            window[c]++;
            if(mp.find(c) != mp.end() and window[c] == mp[c]) have+=1;
            while (have == need){
                if((r-l+1) < reslen){
                    reslen=r-l+1;
                    res={l,r};
                }
                window[s[l]]--;
                if( mp.find(s[l]) != mp.end() and window[s[l]]< mp[s[l]]) have-=1;
                l+=1;
            }
        }
        
        return reslen == INT_MAX ? "":s.substr(res.first,reslen);
    }
};
