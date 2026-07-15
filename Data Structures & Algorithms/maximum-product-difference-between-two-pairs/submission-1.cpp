class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int mx1=0, mx2=0;
        int min1=INT_MAX,min2=INT_MAX;
        for(int x: nums){
            if(x>mx1) {
                mx2=mx1;
                mx1=x;
            }
            else if(x>mx2) {
                mx2=x;
            }
            if(x<min1){
                min2=min1;
                min1=x;
            }
            else if(x<min2){
                min2=x;
            }
        }
        return mx1*mx2-min1*min2;
    }
};