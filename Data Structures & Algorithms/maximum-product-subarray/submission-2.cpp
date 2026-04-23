class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int res = nums[0];
       int cu_min=1,cur_max=1;
       for( int num: nums){
        int temp = cur_max*num;
        cur_max=max(max(temp,num*cu_min), num);
        cu_min=min(min(temp,num*cu_min), num);
        res=max(res,cur_max);
       }
       return res;
    }
};
