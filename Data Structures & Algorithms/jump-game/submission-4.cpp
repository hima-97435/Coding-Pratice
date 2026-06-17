class Solution {
public:
    bool canJump(vector<int>& nums) {
        // int i=0;
        // while(i<nums.size()){
        //     int step = nums[i];
        //     if(step == 0) break; 
        //     for( int i=1;i<=step;i++){
        //          if( i == nums.size()) break;
        //             i+=step;
        //     }
        // }
        // return i >= nums.size()-1;
        return dfs(nums,0);
    }
    bool dfs(vector<int>&nums, int i){
        if(i == nums.size()-1) return true;
        int end = min((int)nums.size()-1,i + nums[i]);
        for(int j=i+1;j<=end;j++){
            if(dfs(nums,j)) return true;
        }
        return false;
    }

};
