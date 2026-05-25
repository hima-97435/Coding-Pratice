class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(nums, 0 , ans, subset);
        return ans;
    }
    void dfs(vector<int>& nums, int index, vector<vector<int>> & ans, vector<int> & subset ){
        if(index== nums.size()){
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums,index+1, ans, subset);
        subset.pop_back();
        while(index+1<nums.size() && nums[index] == nums[index+1]) index++;
        dfs(nums, index+1, ans, subset);

    }
};
