class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for( int i=0;i<nums.size();i++){
            int sum =1;
            for( int j=0;j<nums.size();j++){
                if(j == i) continue;
                sum*=nums[j];
            }
            res.push_back(sum);
        }
        return res;
    
    }
};
/*
[1,2,4,6]
prefix = [1,2,8,48]
suffix= []
*/
