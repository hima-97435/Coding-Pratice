class Solution {
public:
void combs( int index , int target, vector<int>& nums, vector<vector<int>>& result, vector<int>& current){
    if(target ==0) {
        result.push_back(current);
        return;
    }
    if( index == nums.size() || target<0) return;
    if(nums[index]<=target) {
        current.push_back(nums[index]);
        combs(index, target-nums[index],nums, result, current);
        current.pop_back();

    }
    combs(index+1, target, nums, result , current);
}
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        combs(0, target, nums, result, current);
        return result;
    }
};
