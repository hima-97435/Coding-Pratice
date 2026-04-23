class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=nums.size();
        vector<int> ans;
        for(int x: nums){
            if( x == val) cnt--;
            else ans.push_back(x);
        }
        nums=ans;
        return cnt;
    }
};