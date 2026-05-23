class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
         vector<vector<int>> ans;
       vector<int> subset;
       sort(nums.begin(), nums.end());
       dfs(nums,0, ans, subset, target);
       return ans;
    }
    void dfs(vector<int>& nums, int indx, vector<vector<int>>& ans, vector<int>& subset, int target){
        if( target == 0  ) {
            ans.push_back(subset);
            return;
        }
        for( int i=indx;i<nums.size();i++){
            if(nums[i]>target) break;
            if(i>indx && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            dfs(nums, i+1, ans, subset, target-nums[i]);
            subset.pop_back();
        }
    }
};
