class Solution {
public:
    int findMin(vector<int> &nums) {
        int mini = INT_MAX;
        for( int x: nums){
            mini=min(x,mini);
        }
        return mini;
    }
};
