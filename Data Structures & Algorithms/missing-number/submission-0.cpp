class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i=0;
        for( int x: nums){
        
            if(x != i) return i;
            i++;
        }
        return nums.size();
    }
};
