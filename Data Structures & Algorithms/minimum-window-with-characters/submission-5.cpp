class Solution {
public:
    string minWindow(string s, string t) {
       unordered_map<char , int> mp;
       int start_index = 0;
       for(char c : t) mp[c]++;
       unordered_map<char, int> mm;
       int l =0, minlen=INT_MAX ;
       int count =0;
       for(int r =0;r<s.size();r++){
        mm[s[r]]++;
        if(mp.count(s[r]) && mm[s[r]] <= mp[s[r]]) count++;
        while(count == t.size()) {
            if(r-l+1 <minlen) {
                minlen=r-l+1;
                start_index =l;
            }
        if(mp.count(s[l]) && mm[s[l]] == mp[s[l]]) count--;
        mm[s[l]]--;
        l++;
        }
       }
       return minlen ==INT_MAX ? "" :s.substr(start_index, minlen);
        
    }
};
