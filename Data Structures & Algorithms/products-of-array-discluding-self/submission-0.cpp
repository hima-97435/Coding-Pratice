class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res;
        for(int i=0;i<n;i++){
            int val =1;
            for( int j=0;j<n;j++){
                if(i == j) continue;
                val*=nums[j];
            }
            res.push_back(val);
        }
        return res;
    }
};
