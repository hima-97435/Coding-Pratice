class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<int> subset;
        dfs(nums, 0 , ans, subset);
        return vector<vector<int>>(ans.begin(),ans.end());
    }
    void dfs(vector<int>& nums, int index, set<vector<int>> & ans, vector<int> & subset ){
        if(index>= nums.size()){
            ans.insert(subset);
            return;
        }
        subset.push_back(nums[index]);
        dfs(nums,index+1, ans, subset);
        subset.pop_back();
        dfs(nums, index+1, ans, subset);

    }
};
