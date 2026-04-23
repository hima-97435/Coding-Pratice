class Solution {
public:
int hrober1(vector<int> &nums, int st, int end){
    if(nums.empty()) return 0;
    if(nums.size() == 1) return nums[0];
    int r1=0;
    int r2=nums[st];
    for( int i=st+1;i<end;i++){
        int temp = max(nums[i]+r1,r2);
        r1=r2;
        r2=temp;
    }
    return r2;
}
    int rob(vector<int>& nums) {
     return max(hrober1(nums,0,nums.size()-1),hrober1(nums,1,nums.size()));
    }
};
