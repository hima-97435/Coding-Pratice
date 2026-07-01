class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        vector<int> res = nums;
        auto cmp = [&](int a, int b){
            if(res[a]!= res[b]) return res[a]>res[b];
            return a>b;
        };
        priority_queue<int , vector<int>, decltype(cmp)> minheap(cmp);
        for(int i=0;i<n;i++) minheap.push(i);
        for(int i=0;i<k;i++){
            int z= minheap.top();
            minheap.pop();
            res[z]*=multiplier;
            minheap.push(z);
        }
        return res;

    }
};