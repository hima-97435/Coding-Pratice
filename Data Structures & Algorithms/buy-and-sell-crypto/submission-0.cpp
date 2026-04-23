class Solution {
public:
    int maxProfit(vector<int>& nums) {
       int ans =0;
       int n = nums.size();
       vector<int> pref(n,INT_MAX),suff(n,INT_MIN);
        pref[0]=nums[0];

       for( int i=1;i<n;i++){
        pref[i]=min(pref[i-1],nums[i]);
       }

        suff[n-1]=nums[n-1];
       for( int i=n-2;i>=0;i--){
        suff[i]=max(suff[i+1],nums[i]);
       }
       for( int i=0;i<n;i++){
        ans= max(ans,abs(suff[i]-pref[i]));
       }
       return ans;
    }
};
