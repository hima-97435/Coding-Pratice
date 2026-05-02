class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int x: nums){
            if(mp.count(x)) return true;
            else mp[x]++;
        }
        return false;
    }
};