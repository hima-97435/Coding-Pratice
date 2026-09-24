class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        auto hb1 = [&](int l , int r)-> int{
            int x = nums[l], y =max(nums[l],nums[l+1]);
            for(int i=l+2;i<=r;i++){
                int tmp= max(y,nums[i]+x);
                x=y;
                y=tmp;
                cout<<x<<" "<<y<<endl;
            }
            return y;
        };
        // cout<<hb1(1,nums.size()-2)<<endl;  

        return max(hb1(0,nums.size()-2), hb1(1,nums.size()-1));
    }

};
