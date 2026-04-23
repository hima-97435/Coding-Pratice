class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    //   map<int , int> mp;
    //   for( int i=0;i<nums.size();i++){
    //     mp[nums[i]]++;
    //   }   
    //   for(auto p: mp){
    //     if(p.second == 2) return true;
    //   }
    //   return false;
    set<int> st;
    for( int i=0;i<nums.size();i++){

        if(st.find(nums[i]) != st.end()) {
            return true;
        }
        else {
            st.insert(nums[i]);
        }


    }
    return false;
    }
};