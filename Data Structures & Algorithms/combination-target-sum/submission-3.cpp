class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(nums, 0 , ans, vec,  target);
        return ans;
    }
    void dfs(vector<int> nums, int index, vector<vector<int>>& ans , vector<int> & vec, int target){
        if(target == 0){
            ans.push_back(vec);
            return;
        }
        if(index == nums.size() || target<0) return;
        vec.push_back(nums[index]);
        dfs(nums, index, ans, vec, target-nums[index]);
        vec.pop_back();
        dfs(nums, index+1, ans, vec, target);
    }
};
