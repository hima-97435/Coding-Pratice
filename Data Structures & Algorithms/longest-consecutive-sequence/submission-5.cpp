class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       // instead use set for fast reterival
        // and checking neighbours quickly
        unordered_set<int> num(nums.begin(), nums.end());
        int longest =0;
        for( int x: num){
            if(num.find(x-1) == num.end()){
                int lenfth =1;
                while(num.find(x+lenfth) != num.end()) lenfth++;
                longest=max(longest,lenfth);
            }
        }
        return longest;

    }
};
