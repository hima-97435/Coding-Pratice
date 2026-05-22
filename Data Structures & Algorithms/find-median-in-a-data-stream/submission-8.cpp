class MedianFinder {
public:
    vector<int> nums;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(), nums.end());
        
        if(nums.size()%2 == 0) {
            int n = nums.size();
            int val = nums[n/2]+ nums[(n/2)-1];
            return val/2.0;
        }
        else {
            int n = nums.size();
            return (double) nums[n/2];
        }
        return -1.0;
    }
};

// [1,2,2,4,5,6]