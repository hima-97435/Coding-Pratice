class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // vector<vector<int>> res;
        // sort(nums.begin(),nums.end());
        // int n = nums.size();
        // for( int i=0;i<n;i++){
        //     // also checks if the element is same.
        //     if(i>0 && nums[i] == nums[i-1]) continue;
        //     int l = i+1,r= n-1;
        //     while(l<r) {
        //         int sum = nums[l]+nums[r]+nums[i];
        //         if(sum ==0 ) {
        //             res.push_back({nums[i], nums[r], nums[l] });
        //             l++;
        //             r--;
        //             // check for duplicates.
        //             // that the element which we are adding is not a same as previous one.
        //             while(l<r && nums[l] == nums[l-1]) l++;
        //             while(l<r && nums[r] == nums[r+1] ) r--;
                    
        //         }
        //         else if(sum<0) l++;
        //         else r--;
        //     }
        // }
        // return res;
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for( int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int l =i+1, r = n-1;
            while(l<r){
                int sum = nums[l]+ nums[i]+ nums[r];
                if( sum == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                    // while(l<r && nums[r] == nums[r+1]) continue;
                }
                else if(sum<0) l++;
                else r--;
            }
        }
        return res;
    }
    
};
