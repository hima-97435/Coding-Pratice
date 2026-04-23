class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // how should i deal with sceanrio like 
        // [1,3,1,4,1];
        // for( int i=0;i<prices.size();i++){
        //     if(prices[i]<prices[i+1]){
        //        int j =i+1;
        //         while(j<prices.size() && prices[j]<prices[j+1]) j++;
        //         return prices[j]-prices[i];
        //     }
        // }
        // return 0;
        int l =0, r =1;
        int n = prices.size();
        int ans =0;
        while(r<n){
            if(prices[l]<prices[r]) {
                int value = prices[r]-prices[l];
                ans=max(ans, value);
            }
            else l =r;
            r++;
        }
        return ans;
    }
};
