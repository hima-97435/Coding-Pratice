class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
        if(nums.size() == 1 ) return nums[0];
        int maxsum = nums[0];
        for(int i=0;i<nums.size();i++){
            int x = accumulate(nums.begin()+i, nums.end(),0);
            maxsum=max(maxsum,x);
        }
        return maxsum;
        This approach is badd , cause it hjsut acalaute from start to back not look intermediate max values.

        */
        int n = nums.size();
        int ans = nums[0];
        if(n == 1) return ans;
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=i;j<n;j++){
                cur+=nums[j];
                ans=max(ans,cur);
            }
        }
        return ans;
    }
};
