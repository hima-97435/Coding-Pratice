class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> num;
       for( int x: nums){
        num[x]++;
       }
       vector<int> res;
        int n = nums.size();
       for(auto& x: num){
        if(x.second > n/3) res.push_back(x.first);
       }
       return res;
    }
};