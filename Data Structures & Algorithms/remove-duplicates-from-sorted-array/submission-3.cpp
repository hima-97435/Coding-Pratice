class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // if(nums.empty()) return 0;
    //    return set<int> (nums.begin(),nums.end()).size();
    int n = nums.size();
    int l =1;
    for( int i=1;i<n;i++){
        if(nums[i-1] != nums[i]) {
            nums[l++]=nums[i];
        }
    }
    return l;
    }
};