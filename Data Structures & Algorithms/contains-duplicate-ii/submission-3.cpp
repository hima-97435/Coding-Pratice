class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       
       unordered_set<int> stt;
       for( int i=0;i<nums.size();i++){
        if(stt.count(nums[i])) return true;
        stt.insert(nums[i]);
        if(stt.size()>k) stt.erase(nums[i-k]);
       }
       return false;
    }

};