class Solution {
public:
    
    bool validWordAbbreviation(string word, string abbr) {
        int p1 =0 , p2 =0;
        int m = word.size();
        int n = abbr.size();
        while(p1<m && p2<n){
            if(abbr[p2] == '0') return false;
            if(isdigit(abbr[p2])){
                int num =0;
                while(p2<n && isdigit(abbr[p2])) {
                    num=num*10+abbr[p2]-'0';
                    p2++;
                }
                p1+=num;
            }
            else {
                if(word[p1] != abbr[p2]) return false;
                p1++;
                p2++;
            }
            

        }
        return p1 == m && p2 == n;
    }
};