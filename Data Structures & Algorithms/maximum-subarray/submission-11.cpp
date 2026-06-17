class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dfs(nums,0,nums.size()-1);
    }
    int dfs(vector<int>& nums, int l , int r){
        if(l>r) return INT_MIN;
        int m = (l+r)>>1;
        int lsum =0, rsum =0, cursum =0;
        for(int i=m-1;i>=l;--i){
            cursum+=nums[i];
            lsum=max(lsum, cursum);
        }
        cursum=0;
        for(int i=m+1;i<=r;++i){
            cursum+=nums[i];
            rsum=max(rsum,cursum);
        }
        return max({dfs(nums , l , m-1) ,dfs(nums,m+1,r),lsum+nums[m]+rsum});
    }
};
