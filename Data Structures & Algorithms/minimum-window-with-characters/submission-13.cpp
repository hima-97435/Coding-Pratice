class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        vector<int> mp(128, 0);
        vector<int> window(128, 0);

        
        int have = 0;
        int need = 0;

        for(char c : t){
            if(mp[c] == 0)
                need++;
            mp[c]++;
        }
            

        int l = 0;
        int reslen = INT_MAX;
        int first = -1;

        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if(mp[c] > 0 && window[c] == mp[c])
                have++;

            while(have == need) {
                if(r - l + 1 < reslen) {
                    reslen = r - l + 1;
                    first = l ;
                }

                window[s[l]]--;

                if(mp[s[l]] > 0 && window[s[l]] < mp[s[l]])
                    have--;

                l++;
            }
        }

        return reslen == INT_MAX ? "" : s.substr(first, reslen);
    }
};