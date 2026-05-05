class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for( int i=0;i<n-k+1;i++){
            int temp = k;
            int j=i;
            int maxval = nums[i];
            while(temp--){
                maxval=max(maxval,nums[j]);
                j++;    
            }
            ans.push_back(maxval);
        }
        return ans;
    }
};
