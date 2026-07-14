class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<string , int> dp;
        int n = prices.size();
        auto dfs = [&] (auto && self, int i, bool buying  ) -> int{
            if(i >= n) return 0;
            string key = to_string(i)+"-"+to_string(buying);
            if(dp.find(key) != dp.end()) return dp[key];
            int cooldown = self(self,i+1,buying);
            if(buying){
                int buy= self(self,i+1,false)-prices[i];
                return dp[key]=max(buy,cooldown);
            }
            else {
                int sell = self(self,i+2,true)+prices[i];
                return dp[key]=max(sell, cooldown);
            }
        };
        return dfs(dfs,0,true);

    }
};
