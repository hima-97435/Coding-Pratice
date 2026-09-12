class Solution {
public:
    int findMaxIndex( vector<int> freq){
        int mindex =0;
        for(int i=1;i<26;i++) {
            if(freq[i]>freq[mindex]) mindex=i;
        }
        return mindex;
    }
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        for(char c: s){
            freq[c-'a']++;
        }
        int maxfreq = *max_element(freq.begin(), freq.end());
        if(maxfreq>(s.size()+1)/2) return "";
        string res;
        while(s.size()>res.size()){
            int mindex= findMaxIndex(freq);
            char maxchar = 'a'+mindex;
            res+=maxchar;
            freq[mindex]--;
            if(freq[mindex] == 0 ) continue;

            int tmp = freq[mindex];
            freq[mindex]=INT_MIN;
            int nxtmaxindex=findMaxIndex(freq);
            char nxtmaxchar = 'a'+nxtmaxindex;
            res+=nxtmaxchar;
            freq[nxtmaxindex]--;
            freq[mindex]=tmp;
        }
        return res;
    }
};