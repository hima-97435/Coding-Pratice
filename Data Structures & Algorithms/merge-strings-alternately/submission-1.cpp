class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int t1 =0, t2 =0;
        string ans ="";
        while(t1<word1.size() && t2<word2.size()){
            ans+=word1[t1];
            t1++;
            ans+=word2[t2];
            t2++;
        }
        while(t1<word1.size()){
            ans+=word1[t1];
            t1++;
        }
        while(t2<word2.size())
{
    ans+=word2[t2];
    t2++;
}
return ans;
    }
};