class Solution {
public:
    int funcx(vector<int>& coins, int amount, int index){
        if(amount == 0) return 0;
        if( index >= coins.size() ||  amount < 0  ) return 1e9; 
        int skip =funcx(coins, amount, index+1);
        int take = 1e9 ;
        if(amount>=coins[index]){
            take = 1+ funcx(coins, amount-coins[index],index);
        }
            
        
        return min(take,skip);
    }
    int coinChange(vector<int>& coins, int amount) {
         int res = funcx(coins, amount, 0);

        return res >= 1e9 ? -1:res;

    }
};
