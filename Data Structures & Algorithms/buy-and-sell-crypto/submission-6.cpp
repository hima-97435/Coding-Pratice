class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxp=0;
        int minbuy=prices[0];
        for( int & se : prices){
            maxp=max(maxp,se - minbuy);
            minbuy=min(minbuy,se);

        }
        return maxp;
    }
};
