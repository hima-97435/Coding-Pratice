class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int suffix =0 , prefix=0;
        int res =nums[0];
        for(int i=0;i<n;i++) {
             suffix = nums[n-1-i]*(suffix==0?1:suffix);
             prefix = nums[i]*(prefix==0?1:prefix);
            res=max({res,suffix,prefix});
        }
        return res;
    }
};
