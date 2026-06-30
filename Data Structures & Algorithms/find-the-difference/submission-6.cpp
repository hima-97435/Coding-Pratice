class Solution {
public:
    char findTheDifference(string s, string t) {
        int sumt =0, sums=0;
        for(char c: s) sums+=c;
        for(char c: t) sumt+=c;
        return (char) (sumt-sums);
    }
};