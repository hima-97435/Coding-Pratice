class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if(a!=0 )pq.push({a,'a'});
        if(b!=0 )pq.push({b,'b'});
        if(c!=0 )pq.push({c,'c'});
        string res ="";
        while(!pq.empty()){
            auto [ cnt , c] = pq.top();
            pq.pop();
            if(res.size()>1 && res[res.size() -1] == c && res[res.size()-2 ] == c) {
                if(pq.empty()) break;
                auto [ cnt2, c2]= pq.top();
                pq.pop();
                res+=c2;
                if(--cnt2>0) pq.push({cnt2,c2});
                pq.push({cnt,c});
            }
            else {
                res+=c;
                if(--cnt>0) pq.push({cnt,c});
            }
        }
        return res;
    }
};