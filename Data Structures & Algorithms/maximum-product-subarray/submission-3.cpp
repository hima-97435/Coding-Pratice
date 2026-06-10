class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curmax= nums[0];
        int curmin = nums[0];
        int maxproduct = nums[0];
        for( int i=1;i<nums.size();i++){
            int val = nums[i];
            if(val<0) swap(curmax, curmin);
            curmax= max(val , curmax*val);
            curmin = min(val, curmin*val);
            maxproduct= max(maxproduct, curmax);
        }
        return maxproduct;
    }
};
