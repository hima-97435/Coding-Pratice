class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxPro=LLONG_MIN;
        for( int strt=0;strt<n;strt++){
            for( int en=strt;en<n;en++){
                long long pro=1;
                for(int k = strt;k<=en;k++){
                    pro*=nums[k];
                }
                maxPro=max(maxPro,pro);
            }
        }
        return maxPro;
    }
};
