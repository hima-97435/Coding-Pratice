class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res =0, count =0;
        for( int x: nums){
            if( count == 0) res = x;
            count+=(x == res) ?-1:1;

        }
        return res;

    }
};