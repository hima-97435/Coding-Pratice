class Solution {
public:
    int maxArea(vector<int>& nums) {
        int n = nums.size();
        int l =0, r = n-1;
        int ans=0;
        while(l<r){
            int value = min(nums[l],nums[r])*(r-l);
            ans = max(ans,value);
            if(nums[l]<nums[r]) l++;
            else r--;
        }
        return ans;
    }
};
