class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // use set DS for it and then simply 
        unordered_set<int> s;
        for(int x: nums){
            if(s.count(x)) return true;
            s.insert(x);
        }
        return false;
    }
};