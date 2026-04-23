class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> m1 ;
        vector<int> m2;
        for( int i=1;i<n;i++){
            m1.push_back(nums[i]);
        }
        for( int i=0;i<n-1;i++){
            m2.push_back(nums[i]);
        }
        return max(nums[0],max(helper(m1),helper(m2)));

    }
    int helper(vector<int> nums){
        int rob1=0,rob2=0;
        for(int n : nums){
            int temp = max( n+rob1,rob2);
            rob1=rob2;
            rob2=temp;
        }
        return rob2;
    }
};
