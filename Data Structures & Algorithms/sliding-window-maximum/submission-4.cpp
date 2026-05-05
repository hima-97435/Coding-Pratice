class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int , int>> hh;
        vector<int> output;
        for( int i=0;i<nums.size();i++){
            hh.push({nums[i],i});
            if(i>=k-1) {
                while(hh.top().second<=i-k) hh.pop();
                output.push_back(hh.top().first);
            }
        }
        return output;
    }
};
