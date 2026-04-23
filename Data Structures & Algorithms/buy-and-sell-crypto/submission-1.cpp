class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int l =0,r =1;
       int ans=0;
       int n = nums.size();

       while(r<n){
        if(nums[l] <nums[r]){
            int profit = nums[r]-nums[l];
            ans= max(ans,profit);
        }
        else {
            l=r;

        }
        r++;
       }
       return ans;
    }
};
