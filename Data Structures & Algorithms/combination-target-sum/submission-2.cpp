class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        dfs(nums,0,ans,a,target);
        return ans;
    }
    void dfs(vector<int>& nums, int indx, vector<vector<int>>& ans, vector<int>& subset, int target){
        if( target == 0  ) {
            ans.push_back(subset);
            return;
        }
        if(indx == nums.size() || target<0) return;
        subset.push_back(nums[indx]);
        dfs(nums, indx, ans, subset, target-nums[indx]);
        subset.pop_back();
        dfs(nums, indx+1, ans, subset, target);
    }
};
