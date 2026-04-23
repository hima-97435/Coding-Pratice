class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        // one way si count number of epeating values 
        // like 3 appear 2 times then answer would be 2c2
        // likewise for 1 ==> 3c2
        unordered_map<int , int > cnt;
        int res =0;
        for( int x: nums){
            cnt[x]++;
        }
        for(auto&[n , c]: cnt){
            res+=c*(c-1)/2;
        }
        return res;
    }
};