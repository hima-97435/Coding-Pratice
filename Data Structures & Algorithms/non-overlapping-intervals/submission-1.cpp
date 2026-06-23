class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end() , [](auto &a, auto&b) {
            return a[1]<b[1];
        });
        int removal=0;
        int prevend = intervals[0][1];
        for(size_t i =1;i<intervals.size();i++){
            if(intervals[i][0]<prevend) removal++;
            else prevend=intervals[i][1];
        }
        return removal;
    }
};
