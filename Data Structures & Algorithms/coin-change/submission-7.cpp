class Solution {
public:
    unordered_map<int , int > mp;
    int coinChange(vector<int>& coins, int amount) {
        int x =dfs(coins,amount); 
        return  x>=INT_MAX ?-1:x;
    }
    int dfs(vector<int> & coins,int target ){
        if(target == 0) return 0;
        if(mp.find(target) != mp.end()) return mp[target];
        int res = INT_MAX;
        for(int c: coins){
            if(target-c>=0) 
            {
                int result = dfs(coins,target-c);
                if(result!= INT_MAX) res=min(res,1+result);
            }
        }
        return mp[target]=res;
    }
};
