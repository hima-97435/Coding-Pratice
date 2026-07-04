class Solution {
public:
    string removeDuplicates(string s, int k) {
        bool changed = true;
        while(changed){
            changed = false;
            for(int i=0;i<s.size();){
                int j = i;
                while(j<s.size() && s[j] == s[i]) j++;
                if(j-i>=k){
                    s.erase(i,k);
                    changed=true;
                    break;
                }
                else {
                    i=j;
                }
            }
        }
        return s;
    }
};