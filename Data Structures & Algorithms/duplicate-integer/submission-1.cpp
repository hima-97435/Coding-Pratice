class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> mp;
        for( int x: nums){
            mp[x]++;

        }
        for( auto t: mp){
            if(t.second >1) return true;
        }
        return false;
    }
};