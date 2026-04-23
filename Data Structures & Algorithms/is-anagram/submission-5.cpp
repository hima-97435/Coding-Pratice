class Solution {
public:
    bool isAnagram(string s, string t) {
        // use map data structure simply.
        vector<int> mp(26,0);
        for(char c : s) mp[c-'a']++;
        for(char c :  t) mp[c-'a']--;
        for(int x : mp) {
            if(x != 0) return false;
        }
        return true;
    }
};
