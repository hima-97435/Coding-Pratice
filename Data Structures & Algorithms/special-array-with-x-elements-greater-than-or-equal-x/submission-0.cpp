class Solution {
public:
    int specialArray(vector<int>& nums) {
        int i=1;
        while(i<=nums.size()){
            int cnt =0;
            for(int x: nums){
                if(x>=i) cnt++; 
            }
            cout<<i<<" ";
            if(cnt  == i) return i;
            i++;
        }
        return -1;
    }
};