class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalsum=0;
        for( int c: nums) totalsum+=c;
        

        if(totalsum%2 != 0) return false;
        int target= totalsum/2;
        vector<bool> dp(target+1, false);
        dp[0]= true;
        for( int x: nums){
            for( int i=target;i>=x;i--){
                if(dp[i-x]) dp[i]=true;
            }
            if(dp[target] ) return true;
        }
        return dp[target];

    }
};
