class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int tt = accumulate(nums.begin(), nums.end(), 0);
        if(abs(target)> tt) return 0;
        if((tt+target)%2 != 0) return 0;
        int subsettarget=(tt+target)/2;
        vector<int> dp(subsettarget+1,0);
        dp[0]=1;
        for( int x: nums){
            for(int i=subsettarget;i>=x;i--){
                    dp[i]+=dp[i-x];
            }
        }
        return dp[subsettarget];
    }
};
