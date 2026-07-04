class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<int> nums(n);
        sort(envelopes.begin(), envelopes.end(), [](vector<int>&a, vector<int>&b){
            if(a[0] != b[0]) return a[0]<b[0];
            return a[1]>b[1];
        });
        for(int i=0;i<n;i++) nums[i]=envelopes[i][1];
        vector<int> dp;
        dp.push_back(nums[0]);
        int lis =1;
        for(int i=1;i<n;i++){
            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
                lis++;
                continue;
            }
            int index = lower_bound(dp.begin(),dp.end(),nums[i])-dp.begin();
            dp[index]=nums[i];
        }
        return lis;
    }
};