class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int l =0 , r =1;
       int n = nums.size();
       int ans =0;
       while(r<n){
        if(nums[l]< nums[r]) {
            int v = nums[r]-nums[l];
            ans = max(ans, v);
        }
        else {
            l = r;
        }
        r++;
       } 
       return ans;
    }
};
