class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
         int n = nums.size();

         int left=lower_bound(nums.begin(), nums.end(), target)-nums.begin();
         int right = upper_bound(nums.begin(), nums.end(), target)- nums.begin();
        return (right-left)>n/2;

    }
};
