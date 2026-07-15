class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq; //max heap
        for(int x: nums) pq.push(x);
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};