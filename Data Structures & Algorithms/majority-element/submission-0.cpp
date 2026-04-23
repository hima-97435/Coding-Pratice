class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> m1;
        int n = nums.size();
        for( int x: nums){
            m1[x]++;
        }
        int ans=0;
        for(auto &p : m1){
            if(p.second >( n /2) )  ans = p.first;
        }
        return ans;
    }
};