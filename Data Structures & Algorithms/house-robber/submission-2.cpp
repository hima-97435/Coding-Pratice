class Solution {
public:
    int rob(vector<int>& nums) {
        int r1=0;
        int r2=nums[0];
        for( int i=1;i<nums.size();i++){
            int val = max(nums[i]+r1,r2);
            int temp = r2;
            r2=val;
            r1=temp;
        }
        return r2;
    }
};
