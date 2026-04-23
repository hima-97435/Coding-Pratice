class Solution {
public:
    bool isAnagram(string s, string t) {
        // use map data structure simply.
        map<char, int> mp,mp1;
        for(char c : s) mp[c]++;
        for(char c :  t) mp1[c]++;
        return mp == mp1;
    }
};
