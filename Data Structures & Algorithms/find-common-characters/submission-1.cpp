class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> map(26,INT_MAX);
        for(string & word: words){
            vector<int> cnt(26,0);
            for(char c: word) cnt[c-'a']++;
            for(int i=0;i<26;i++){
                map[i]=min(map[i],cnt[i]);
            }
        }
        vector<string> res ;
        for(int i=0;i<26;i++){
            for(int j=0;j<map[i];j++){
                res.push_back(string(1,i+'a'));
            }
        }
        return res;

        
    }
};