class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int cnt =0;
        unordered_map<int, int> mp;
        auto dfs = [&] ( auto &&self, int amount) ->int{
            if(amount == 0 ) return 0;
            if(mp.find(amount) != mp.end()) return mp[amount];
            int res =1e9;
            for(int x: coins){
                if(amount-x>=0) res=min(res,1+self(self,amount-x));
            }
            return mp[amount]=res;
        };
        int mincoins = dfs(dfs,amount);
        return mincoins>=1e9?-1:mincoins;
    }
};
