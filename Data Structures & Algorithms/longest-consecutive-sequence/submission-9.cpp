class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int longeststreak=0;
        for( int num : numset){
            if(numset.find(num-1) == numset.end()) {
                int currentNum = num;
                int currentstreak = 1;
                while(numset.find(currentNum+1) != numset.end()) {
                    currentNum+=1;
                    currentstreak+=1;

                }
                longeststreak=max(longeststreak, currentstreak);
            }
        }
        return longeststreak;
    }
};
