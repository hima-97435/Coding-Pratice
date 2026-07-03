class Solution {
public:
    unordered_map<int , int> mp;

    int numSquares(int n) {
        return dfs(n);
    }
    int dfs(int target ){
        // cout<<target<<" ";
        if(target == 0) return 0;
        if(mp.count(target)) return mp[target];
        int res = target;
        for(int i=1;i*i<=target;i++){
            res= min(res,1+dfs(target-i*i));
        }
        return mp[target]=res;
    }
};