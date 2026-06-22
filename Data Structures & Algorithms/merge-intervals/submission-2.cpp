class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        int n = intervals.size();
        for( int i=0;i<n;i++){
            int start  = intervals[i][0];
            int end = intervals[i][1];
            if(start<=res.back()[1]){
               res.back()[1]=max(end, res.back()[1]);
            } else {
                res.push_back({start,end});
            }

        }
        return res;
    }
};
