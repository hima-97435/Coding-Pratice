class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // nums=[1,2,4,6] 
        // prefix= [0,1,2,8] -->wrong
        // suffix= [48,24,6,0] -->wrong
        // prefix =[1,1,2,8] --> right
        // suffix=[48,24,6,1] -->right
        int n = nums.size();
        vector<int> prefix (n);
        vector<int> suffix (n);
        vector<int> res(n);
        prefix[0]=1;
        suffix[n-1]=1;
        for( int i=1;i<n;i++) prefix[i]=prefix[i-1]*nums[i-1];
        for( int i=n-2;i>=0;i--) suffix[i]=suffix[i+1]*nums[i+1];
        for( int i=0;i<n;i++) res[i]=prefix[i]*suffix[i];
        return res;
    }
};
