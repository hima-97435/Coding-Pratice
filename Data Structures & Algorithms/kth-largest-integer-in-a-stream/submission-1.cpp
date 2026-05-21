class KthLargest {
public:
int ksize;
priority_queue<int , vector<int> , greater<int> > pq;

    KthLargest(int k, vector<int>& nums) {
        ksize=k;
        for( int num : nums) add(num);
     }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>ksize) pq.pop();
        return pq.top();
    }
};
