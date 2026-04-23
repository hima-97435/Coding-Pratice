class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    //    sort(nums.begin(),nums.end());
    //    itn an = 0;
    //    for( int i=0;i<nums.size();i++){
    //     if(nums[i])
    //    }
    unordered_map<int , int> mp;
    for(int x: nums) mp[x]++;
    // int val = INT_MAX;
    int i=1;
    while(true) {
        if(mp.find(i) == mp.end()) break;
        i++;
    }
    return i;



    }
};