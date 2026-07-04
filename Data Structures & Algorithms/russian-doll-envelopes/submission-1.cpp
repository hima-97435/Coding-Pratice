class Solution {
public:
vector<int> nums, dp;
int n;
int dfs(int i){
    if(dp[i] != -1) return dp[i];
    int lis = 1;
    for(int j=i+1;j<n;j++) {
       if(nums[i]<nums[j])  lis=max(lis,1+dfs(j));
    }
    return dp[i]=lis;
}
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        n= envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b){
            if(a[0] != b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        nums.resize(n);
        for(int i=0;i<n;i++) nums[i]=envelopes[i][1];
        dp.assign(n,-1);
        int res =0;
        for(int i=0;i<n;i++){
            res=max(res, dfs(i));
        }
        return res;

    }
};