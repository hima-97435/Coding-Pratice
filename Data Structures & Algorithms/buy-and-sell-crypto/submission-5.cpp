class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l =0, r =1;
        int cost =0;
        while(r<prices.size()) {
            if(prices[l]<prices[r]) {
                int p = prices[r]-prices[l];
                cost=max(p,cost);
            }
            else l =r;
            r++;
        }
        return cost;
    }
};
