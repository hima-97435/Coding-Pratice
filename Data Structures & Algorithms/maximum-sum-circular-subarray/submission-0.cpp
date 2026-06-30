class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            int sum =0;
            for(int j=0;j<n;j++){
                sum+=nums[(i+j)%n];
                ans=max(ans,sum);
            }
        }
        return ans;
    }
};