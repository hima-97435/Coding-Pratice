class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char , int> mp;
        for(char c: s1) mp[c]++;
        unordered_map<char, int> mm;
        int h =0;
        for(int i=0;i<s2.size();i++){
            mm[s2[i]]++;
            if((i-h+1) > s1.size()) {
                mm[s2[h]]--;
                if(mm[s2[h]] == 0) {
                    mm.erase(s2[h]);
                }
                h++;
            }
            if(mm == mp) return true;
        }
        return false;
    }
};
