class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0], cursum=0;
        for(int n : nums){
            if(cursum<0) cursum=0;
            cursum+=n;
            maxsum=max(maxsum,cursum);
        }
        return maxsum;
    }
};
