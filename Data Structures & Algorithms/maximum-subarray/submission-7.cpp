class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        return dfs(0,false, nums);
    }
    int dfs(int i, bool flag , vector<int>& nums){
        if( i == nums.size()-1) return flag?max(0, nums[i]):nums[i];
        // 0 here menat stpping the array
        if(flag) return max(0,nums[i]+dfs(i+1,true, nums));
        else return max(dfs(i+1,false,nums),nums[i]+dfs(i+1,true,nums));
    }
};
