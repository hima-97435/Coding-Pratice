class KthLargest {
public:
int K;
vector<int> ans;
    KthLargest(int k, vector<int>& nums) {
        K=k;
        ans=nums;
    }
    
    int add(int val) {
        ans.push_back(val);
        sort(ans.rbegin(),ans.rend());
        return ans[K-1];
        
    }
};
