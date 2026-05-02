class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans =INT_MIN;
        int n = nums.size();
        if( n == 0) return 0;
        for( int i=0;i<n;i++){
            if(st.find(nums[i]-1) == st.end()) {
                int j=1;
                while(st.find(nums[i]+j) != st.end()) {
                    cout<<"YES"<<" ";
                    j++;
                }
                ans=max(ans,j);
            }
        }
        return ans;
    }
};
