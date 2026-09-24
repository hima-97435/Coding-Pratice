class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        int ans =0;
        auto atmostk = [&](int k )-> int{
            unordered_map<int, int>mp;
            int res =0 , l=0;
            for(int r=0;r<n;r++){
                mp[nums[r]]++;
                if(mp[nums[r]] == 1) k--;
                while(k<0){
                    mp[nums[l]]--;
                    if(mp[nums[l]] == 0) k++;
                    l++;
                }
                res+=(r-l+1);
            }
            return res;
        };
        return atmostk(k)-atmostk(k-1);
    }
};