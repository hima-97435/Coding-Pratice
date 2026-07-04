class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> count(26,0);
        for(int i=0;i<s.size();i++){
            count[s[i]-'a']=i;
        }
        vector<int> result;
        int st =0, en =0;
        for(int i=0;i<s.size();i++){
            en=max(en,count[s[i]-'a']);
            if( i == en) {
                result.push_back(en-st+1);
                st=i+1;
            }
        }
        return result;
    }
};
