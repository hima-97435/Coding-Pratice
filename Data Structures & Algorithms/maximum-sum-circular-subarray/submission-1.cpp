class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalmax= nums[0], globalmin=nums[0];
        int curmax =0, curmin=0, total = 0 ;
        for(int x: nums){
            curmax=max(curmax+x,x);
            curmin=min(curmin+x,x);
            total+=x;
            globalmax=max(globalmax,curmax);
            globalmin=min(globalmin,curmin);
        }
        return globalmax>0?max(globalmax,total-globalmin):globalmax;

    }
};