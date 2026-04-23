class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 =0,l2=0;
        string ans ="";
        while(l1<word1.size() && l2<word2.size()) {
            ans+=word1[l1++];
            ans+=word2[l2++];

        }
        while(l1<word1.size() ) ans+=word1[l1++];
        while(l2<word2.size()) ans+=word2[l2++];

        return ans;
    }
};