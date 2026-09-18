class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [] (auto&a, auto&b){
            if(a[0] != b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        vector<int> nums(n), cache(n,-1);
        auto dfs = [&](auto &&self, int i)->int{
            if(cache[i] != -1) return cache[i];
            int lis =1;
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]) lis=max(lis,1+self(self,j));
            }
            return cache[i]=lis;
        };
        for(int i=0;i<n;i++) nums[i]=envelopes[i][1];
        int res =0;
        for(int i=0;i<n;i++){
            res=max(res,dfs(dfs,i));
        }
        return res;
    }
};