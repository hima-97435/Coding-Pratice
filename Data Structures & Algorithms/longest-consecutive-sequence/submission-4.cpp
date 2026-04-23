class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> numset(nums.begin(),nums.end());
        int longet=0;
        for( int x : numset) {
            if(numset.find(x-1) == numset.end()) {
                int len =1;
            while(numset.find(x+len) != numset.end()) {
                len++;
            }
            longet=max(longet,len);
            }

           
        }
        return longet;
        
    }
};
