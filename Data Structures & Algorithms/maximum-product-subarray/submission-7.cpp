class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans =nums[0];
        for(int i=0;i<nums.size();i++){
            int pr = 1;
            for(int j=i;j<nums.size();j++){
            //    cout<<pr<<" "<<ans<<endl;
                pr*=nums[j];
                ans=max(ans,pr);
            }
        }
        return ans;
    }
};
