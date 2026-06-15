class Solution {

public:
    vector<vector<int>> dp;
    int tt;

    int findTargetSumWays(vector<int>& nums, int target) {
        tt=accumulate(nums.begin(), nums.end(),0);
        dp=vector<vector<int>> ( nums.size(), vector<int>(2*tt+1, INT_MIN));
        return backtrack(0,0, nums, target);
    }
    int backtrack(int i, int total, vector<int> nums, int target){
        if(i == nums.size()) return total == target;
        if(dp[i][total+tt] != INT_MIN) return dp[i][total+tt];
        dp[i][total+tt]= backtrack(i+1,total+nums[i], nums, target)+backtrack(i+1,total-nums[i], nums, target);
        return dp[i][total+tt]; 
    }
};
