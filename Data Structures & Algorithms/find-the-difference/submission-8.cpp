class Solution {
public:
    char findTheDifference(string s, string t) {
        int rs =0;
        for(char c: s) {
            rs^=c;
        }
        for(char c: t){
            rs^=c;
        }
        return (char) (rs);
    }
};