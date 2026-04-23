class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // i have an apparoach.
        map<vector<int>, vector<string>> mp;
        for(const string& s: strs){
            // string t = s;
            // sort(t.begin(),t.end());
            // mp[t].push_back(s);
            vector<int> count(26,0);
            for(char c: s) {
                count[c-'a']++;
            }
            mp[count].push_back(s);
        }
        vector<vector<string>> res;
        for(auto & s: mp){
            res.push_back(s.second);
        }
        return res;

    }
};
// Basically, the approach which I am thinking is like simply storing
//  by every character. For the anagram, what we did is we checked 
// every occurrence of the characters,
//  like "cat" is like "c pe ek hoga character", "a pe ek hoga", 
// or "t pe ek hoga". If you see, if you just simply assume a whole 
// array of 26 size which contains the lowercase letter "c", it would 
// form a unique character. Likewise, other also "swing" forms a unique 
// character, a unique array.  
// Based on that uniqueness, we can form one of the keys for a map,
//  and we are throwing that. For the associated with that particular key
// , we will keep the multiple values, as it is. I just measured dear 
// things like this.
