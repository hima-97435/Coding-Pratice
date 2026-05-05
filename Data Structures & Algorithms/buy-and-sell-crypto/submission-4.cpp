class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int cost = INT_MIN;
        for( int i=0;i<n;i++){
            int val = 0;
            for( int j=i+1;j<n;j++){
                val=max(val,prices[j]-prices[i]);
            }
            cost=max(cost,val);
        }
        return cost;
    }
};
