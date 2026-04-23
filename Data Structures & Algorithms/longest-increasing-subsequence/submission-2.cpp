class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
       return dfs(nums,0,-1);
    }
    private:
    int dfs(vector<int>&nums,int i , int j){
        if(i == nums.size()) return 0;
        int Li= dfs(nums,i+1,j);
        if(j==-1 || nums[j]<nums[i]) Li=max(Li,1+dfs(nums,i+1,i));
        return Li;
    }
    
};
