class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!= t.size()) return false;
        unordered_map<char, char> mp;
        unordered_set<char> st;
        for(int i=0;i<s.size();i++){
            cout<<"i: "<<i<<" "<<"S : "<<s[i]<<" "<<"T : "<<t[i]<<endl;
            if(mp.find(s[i]) == mp.end())  {
                if(st.find(t[i]) != st.end()) return false;
                mp[s[i]]=t[i];
                st.insert(t[i]);
            }
            if(mp[s[i]] != t[i]) return false;
        }
        return true;

    }
};