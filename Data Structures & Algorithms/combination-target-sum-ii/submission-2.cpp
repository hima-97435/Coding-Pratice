class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        set<vector<int>> ans;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        dfs(nums,0, ans, subset, target);
        return vector<vector<int>> (ans.begin(), ans.end());
    }
    void dfs(vector<int> nums, int index, set<vector<int>>& ans, vector<int>& subset, int target){
        if(target == 0) {
            ans.insert(subset);
            return;
        }
        // if(index  == nums.size() || target<0) return;
        // subset.push_back(nums[index]);
        // dfs(nums, index+1, ans,subset, target-nums[index]);
        // subset.pop_back();
        // dfs(nums, index+1, ans, subset, target);
        for( int i= index;i<nums.size();i++){
            if(nums[i]> target) break;
            if(i> index &&  nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            dfs(nums, i+1, ans, subset, target-nums[i]);
            subset.pop_back();
        }
    }
};
