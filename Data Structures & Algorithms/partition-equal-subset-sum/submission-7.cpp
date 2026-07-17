class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(),0);
        if(sum%2 != 0) return false;
        else {
            auto subsetsum = [&](auto && self , int i, int target) -> bool {
                if(target == 0) return true;
                if( i == n) return false;
                if(nums[i]>target) return self(self,i+1,target);
                return self(self,i+1,target-nums[i]) || self(self,i+1, target);
            };
            return subsetsum(subsetsum,0,sum/2);
        }
    }
};
