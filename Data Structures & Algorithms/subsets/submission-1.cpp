class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> subset;
       dfs(nums,0, ans, subset);
       return ans;
    }
    void dfs(vector<int>& nums, int indx, vector<vector<int>> &ans, vector<int> & subset){
        if(indx>= nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[indx]);
        dfs(nums, indx+1, ans, subset);
        subset.pop_back();
        dfs(nums, indx+1, ans, subset);
    }
};
