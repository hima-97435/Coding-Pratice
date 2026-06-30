class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> orderindex(26,0);
        for(int i=0;i<order.size();i++){
            orderindex[order[i]-'a']=i;
        }
        for(int i=0;i<words.size()-1;i++){
            string w1 =words[i],w2=words[i+1];
            int j=0;
            for(;j<w1.size();j++){
                if(j == w2.size()) return false;
                if(w1[j] != w2[j]) {
                    if(orderindex[w1[j]-'a'] > orderindex[w2[j]-'a'] ) return false;
                    break;
                }
            }
        }
        return true;

    }
};