class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> sst(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        while(!q.empty()){
            auto [ word, steps ] = q.front();
            q.pop();
            if(word == endWord) return steps;
            for(int i=0;i<word.length();i++){
                char orginword=word[i];
                for(char c = 'a';c<='z';c++){
                    word[i]=c;
                    if(sst.find(word) != sst.end()){
                        sst.erase(word);
                        q.push({word,steps+1});
                    }
                }
                word[i]= orginword;
            }
        }
        return 0;
    }
};
