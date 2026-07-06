class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ne, po;
        for(int x: nums) {
            if(x>0) po.push_back(x);
            else ne.push_back(x);
        }
       int i=0;
       while(2*i<nums.size()){
        nums[2*i]=po[i];
        nums[2*i+1]=ne[i];
        i++;
       }
       return nums;

    }
};