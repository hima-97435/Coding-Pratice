class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l =0,r = nums.size()-1;
        while(l<r){
            int cur= nums[l]+nums[r];
            if(cur>target) r--;
            else if( cur< target) l++;
            else return{l+1,r+1};
        }
        return {};
    }
};
