class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        queue<int>q;
        q.push(0);
        vector<bool>seen(amount+1,false);
        seen[0]= true;
        int rr =0;
        while(!q.empty()){
            rr++;
            int sz = q.size();
            for(int i=0;i<sz;i++){
                int cur = q.front();
                q.pop();
                for(int x: coins){
                    int nxt = cur+x;
                    if(nxt == amount) return rr;
                    if(nxt>amount || seen[nxt]) continue;
                    seen[nxt]= true;
                    q.push(nxt);
                }
            }
        }
        return -1;
    } 
};
