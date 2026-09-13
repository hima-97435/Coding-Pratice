class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l =*max_element(nums.begin(),nums.end());
        int r = accumulate(nums.begin(), nums.end(),0 );
        int ans = r;
        auto  canspilt = [&](int largest)->bool{
            int subarray =1, cursum =0;
            for(int x: nums){
                cursum+=x;
                if(cursum>largest){
                    subarray++;
                    if(subarray>k) return false;
                    cursum = x;
                }
            }
            return true;
        };
        while(l<=r){
            int m = (l+r)>>1;
            if(canspilt(m)){
                ans=m;
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};