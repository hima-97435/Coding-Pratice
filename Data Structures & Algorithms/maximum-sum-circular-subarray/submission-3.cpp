class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int gmx = nums[0], gmn= nums[0];
        int curmx = 0, curmn =0, total=0;
        for(int x: nums){
            curmx =max(curmx+x,x);
            curmn = min(curmn+x,x);
            total+=x;
            gmx=max(gmx,curmx);
            gmn = min(gmn,curmn);
        }
        return gmx>0 ? max(gmx,total-gmn):gmx;
    }
};