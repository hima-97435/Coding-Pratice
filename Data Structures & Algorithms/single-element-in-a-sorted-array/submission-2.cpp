class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l =0, r = n-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if((m-1)<0 || nums[m-1]!=nums[m] &&
             (m+1 == n || nums[m] != nums[m+1])) {
                return nums[m];
            }
            int leftsize=0;
            if(m-1>=0 && nums[m-1] == nums[m] )  leftsize = m-1;
            else leftsize =m ;
            // int leftsize = (m-1 >= 0 && nums[m-1] == nums[m] ) > m-1 : m;
            if(leftsize%2 == 0) l = m+1;
            else r = m-1; 
        }
        return -1;
    }
};