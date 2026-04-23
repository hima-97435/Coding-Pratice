class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> m1;
        map<char,int> m2;

        for( char c : s) m1[c]++;
        for( char c : t) m2[c]++;

        int n = m1.size();
        int m = m2.size();

        if(n!=m) return false;
        else {
            for( auto it: m1){
                int num = it.first;
                int occ = it.second;
                if( m2.find(num) == m2.end()) return false;
                if(occ != m2[num]) return false;
                
                // handle case when a charctree in a map m1 is not in m2 map.
            }
        }
        return true;
    }
};
