class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long maxPro=LLONG_MIN;
        for( int strt=0;strt<n;strt++){
            long long pro=1;
            for( int en=strt;en<n;en++){
                  pro*=nums[en];
                
                maxPro=max(maxPro,pro);
            }
        }
        return maxPro;
    }
};
