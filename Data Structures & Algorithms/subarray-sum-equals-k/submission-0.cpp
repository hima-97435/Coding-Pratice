class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
         int b=0;
         int cnt=0;
        for( int i=0;i<n;i++){
            b=nums[i];;
            if( b == k ) cnt++; 
            for( int j=i+1;j<n;j++){
                b+=nums[j];
                if(b == k) cnt++;
            }
        }
        return cnt;
    }
};