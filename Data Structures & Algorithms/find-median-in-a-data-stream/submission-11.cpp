class MedianFinder {
public:
    priority_queue<int> maxheap;
    priority_queue<int , vector<int> , greater<int>> minheap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxheap.push(num);
        if(!minheap.empty() && maxheap.top() > minheap.top()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(maxheap.size()> minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        if(minheap.size()> maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(minheap.size() == maxheap.size()) return (minheap.top()+maxheap.top())/2.0;
        else if(maxheap.size() > minheap.size()) return maxheap.top();
        else return minheap.top();
    }
};
