class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());
        int ans = 1;
        int actual_ans = 1;
        for( int i=1;i<nums.size();i++){
           if(nums[i]!=nums[i-1]){
            if(nums[i] - 1 == nums[i-1]) ans++;
            else {
                actual_ans=max(actual_ans, ans);
                ans=1;
            }
           }
        }
        return max(actual_ans, ans);

    }
};
