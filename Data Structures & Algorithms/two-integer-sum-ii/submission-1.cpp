class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
   int l =0, r = nums.size()-1;
   while(l<r) {
    int cur_sum= nums[l]+nums[r];
    if(cur_sum > target) r--;
    else if(cur_sum < target) l++;
    else return{l+1,r+1};
   }
   return {};
    }
};
