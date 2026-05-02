class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // sort(nums.begin(), anums.end());
       unordered_map<int , int> mp;
       for( int i=0;i<nums.size();i++){
        if(mp.count(target-nums[i])) 
        // return { mp[i],i};
       {
        cout<<nums[mp[i]]<< " "<<nums[i];
        cout<<endl;
        return {mp[target-nums[i]], i};
       }
        else mp.insert({nums[i],i});
       }
       
       return {1,-1};
    }
};
