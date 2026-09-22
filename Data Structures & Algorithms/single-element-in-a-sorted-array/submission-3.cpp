class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l =0 , r = n-1;
        while(l<=r){
            int m = (l+r)>>1;
            if(
            (m-1<0 or nums[m]!= nums[m-1]) and
            (m == n-1 or nums[m] != nums[m+1]) 
            )
            return nums[m];
            int leftsize = 0;
            if(m-1>=0 and nums[m] == nums[m-1]) leftsize=m-1;
            else leftsize = m;
            if(leftsize%2 == 1) r = m-1;
            else l = m+1;
        }
        return -1;
    }
};