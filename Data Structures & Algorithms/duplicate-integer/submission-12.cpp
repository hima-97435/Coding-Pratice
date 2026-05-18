class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int , int> mmp;
        for( int x: nums) mmp[x]++;
        for(auto p : mmp) {
            if(p.second >= 2) return true;

        }
        return false;
    }
};