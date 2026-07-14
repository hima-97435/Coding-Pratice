class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      unordered_map<int , int> mp;
       auto dfs = [&] (auto&&self, int target)->int {
            if(target == 0 ) return 0;
            if(mp.find(target) != mp.end()) return mp[target];
            int res = 1e9;
            for(int c: coins) {
                if(target-c>=0) {
                    res=min(res,1+self(self,target-c));
                }
            }
            return mp[target]=res;
       };
       int mincoins=dfs(dfs,amount);
       return mincoins>=1e9?-1:mincoins;
    }
};
